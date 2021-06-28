#pragma once

#include <comet/base/types.hpp>
#include <comet/events/key_events/key_event.hpp>
#include <comet/events/window_events/window_close_event.hpp>
#include <comet/events/window_events/window_resize_event.hpp>

namespace comet
{
    struct Event
    {
        enum class Type
        {
            Keyboard,
            WindowClose,
            WindowResize
        };

        Event(const KeyEvent &key_event);

        Event(const WindowCloseEvent &window_close_event);

        Event(const WindowResizeEvent &window_resize_event);

        Type get_type() const;

        KeyEvent as_key_event() const;

        WindowCloseEvent as_window_close_event() const;

        WindowResizeEvent as_window_resize_event() const;

    private:
        const Type type;
        const Variant<KeyEvent, WindowCloseEvent, WindowResizeEvent> event;
    };
}
