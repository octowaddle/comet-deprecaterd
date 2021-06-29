#include <comet/events/event.hpp>
#include <comet/exceptions/exception.hpp>

namespace comet
{
    Event::Event(const KeyPressedEvent &key_pressed_event)
    : type(Type::KeyPressed)
    , event(key_pressed_event)
    {
    }

    Event::Event(const KeyReleasedEvent &key_released_event)
    : type(Type::KeyReleased)
    , event(key_released_event)
    {
    }

    Event::Event(const WindowCloseEvent &window_close_event)
    : type(Type::WindowClose)
    , event(window_close_event)
    {
    }

    Event::Event(const WindowResizeEvent &window_resize_event)
    : type(Type::WindowResize)
    , event(window_resize_event)
    {
    }

    Event::Type Event::get_type() const
    {
        return type;
    }

    KeyPressedEvent Event::as_key_pressed_event() const
    {
        if (type == Type::KeyPressed)
        {
            return std::get<KeyPressedEvent>(event);
        }
        else
        {
            throw Exception("Tried to get wrong event type.");
        }
    }

    KeyReleasedEvent Event::as_key_released_event() const
    {
        if (type == Type::KeyReleased)
        {
            return std::get<KeyReleasedEvent>(event);
        }
        else
        {
            throw Exception("Tried to get wrong event type.");
        }
    }

    WindowCloseEvent Event::as_window_close_event() const
    {
        if (type == Type::WindowClose)
        {
            return std::get<WindowCloseEvent>(event);
        }
        else
        {
            throw Exception("Tried to get wrong event type.");
        }
    }

    WindowResizeEvent Event::as_window_resize_event() const
    {
        if (type == Type::WindowResize)
        {
            return std::get<WindowResizeEvent>(event);
        }
        else
        {
            throw Exception("Tried to get wrong event type.");
        }
    }
}
