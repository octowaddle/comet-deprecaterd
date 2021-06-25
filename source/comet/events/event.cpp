#include <comet/events/event.hpp>
#include <comet/exceptions/exception.hpp>

namespace comet
{
    Event::Event(const KeyEvent &key_event)
    : type(Type::Keyboard)
    , event(key_event)
    {
    }

    Event::Event(const WindowEvent &window_event)
    : type(Type::Window)
    , event(window_event)
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

    WindowEvent Event::as_window_event() const
    {
        if (type == Type::Window)
        {
            return std::get<WindowEvent>(event);
        }
        else
        {
            throw Exception("Tried to get wrong event type.");
        }
    }
}
