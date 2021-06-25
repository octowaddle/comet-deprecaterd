#pragma once

#include <comet/base/types.hpp>
#include <comet/events/key_events/key_event.hpp>
#include <comet/events/window_events/window_event.hpp>

namespace comet
{
    struct Event
    {
        enum class Type
        {
            Keyboard,
            Window
        };

        Event(const KeyEvent &key_event);

        Event(const WindowEvent &window_event);

        Type get_type() const;

        KeyEvent as_key_event() const;

        WindowEvent as_window_event() const;

    private:
        const Type type;
        const Variant<KeyEvent, WindowEvent> event;
    };
}
