#include <comet/events/window_events/window_event.hpp>
#include <comet/exceptions/exception.hpp>

namespace comet
{
    WindowEvent::WindowEvent(const WindowCloseEvent &window_close_event)
    : type(Type::Close)
    , event(window_close_event)
    {
    }

    WindowEvent::WindowEvent(const WindowResizeEvent &window_resize_event)
    : type(Type::Resize)
    , event(window_resize_event)
    {
    }

    WindowEvent::Type WindowEvent::get_type() const
    {
        return type;
    }

    WindowCloseEvent WindowEvent::as_window_close_event() const
    {
        if (type == Type::Close)
        {
            return std::get<WindowCloseEvent>(event);
        }
        else
        {
            throw Exception("Tried to get wrong window event type.");
        }
    }

    WindowResizeEvent WindowEvent::as_window_resize_event() const
    {
        if (type == Type::Resize)
        {
            return std::get<WindowResizeEvent>(event);
        }
        else
        {
            throw Exception("Tried to get wrong window event type.");
        }
    }
}
