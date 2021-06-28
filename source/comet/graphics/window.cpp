#define COMET_INCLUDE_EXTERNAL
#include <comet/graphics/window.hpp>
#include <comet/exceptions/exception.hpp>
#include <comet/base/external.hpp>
#include <iostream>

namespace comet
{
    Window::Window(const u32 width, const u32 height, const String &title)
    {
        if (!glfwInit())
        {
            throw Exception("Failed to initialize GLFW.");
        }

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (handle == nullptr)
        {
            throw Exception("Failed to create window.");
        }

        glfwSetWindowUserPointer((GLFWwindow *) handle, &event_queue);
        glfwMakeContextCurrent((GLFWwindow *) handle);
        glfwSwapInterval(1);

        glfwSetWindowSizeCallback((GLFWwindow *) handle, [](GLFWwindow *window, int width, int height)
        {
            EventQueue *event_queue = (EventQueue *) glfwGetWindowUserPointer(window);
            Event event(WindowResizeEvent(width, height));
            event_queue->enqueue(event);
        });
    }

    Window::Window(Window &&other)
    {
        handle = other.handle;
        other.handle = nullptr;
    }

    Window::~Window()
    {
        glfwDestroyWindow((GLFWwindow *) handle);
    }

    Window &Window::operator=(Window &&other)
    {
        if (this != &other)
        {
            handle = other.handle;
            other.handle = 0;
        }

        return *this;
    }

    bool Window::close_requested() const
    {
        return glfwWindowShouldClose((GLFWwindow *) handle);
    }

    void Window::update() const
    {
        glfwPollEvents();
        glfwSwapBuffers((GLFWwindow *) handle);
    }

    bool Window::events_queued() const
    {
        return !event_queue.empty();
    }

    Event Window::poll_event()
    {
        return event_queue.dequeue();
    }
}
