#pragma once

#include <comet/base/types.hpp>
#include <comet/events/key_events/key_pressed_event.hpp>
#include <comet/events/key_events/key_released_event.hpp>
#include <comet/events/window_events/window_close_event.hpp>
#include <comet/events/window_events/window_resize_event.hpp>

namespace comet
{
    struct Event
    {
        enum class Type
        {
            KeyPressed,
            KeyReleased,
            WindowClose,
            WindowResize
        };

        Event(const KeyPressedEvent &key_pressed_event);

        Event(const KeyReleasedEvent &key_released_event);

        Event(const WindowCloseEvent &window_close_event);

        Event(const WindowResizeEvent &window_resize_event);

        Type get_type() const;

        KeyPressedEvent as_key_pressed_event() const;

        KeyReleasedEvent as_key_released_event() const;

        WindowCloseEvent as_window_close_event() const;

        WindowResizeEvent as_window_resize_event() const;

    private:
        const Type type;
        const Variant<KeyPressedEvent, KeyReleasedEvent, WindowCloseEvent, WindowResizeEvent> event;
    };
}
