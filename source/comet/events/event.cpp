#include <comet/events/event.hpp>
#include <comet/exceptions/exception.hpp>

namespace comet
{
    Event::Event(const KeyEvent &key_event)
    : type(Type::Keyboard)
    , event(key_event)
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

    KeyEvent Event::as_key_event() const
    {
        if (type == Type::Keyboard)
        {
            return std::get<KeyEvent>(event);
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
