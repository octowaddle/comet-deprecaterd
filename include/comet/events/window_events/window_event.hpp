#pragma once

#include <comet/base/types.hpp>
#include <comet/events/window_events/window_close_event.hpp>
#include <comet/events/window_events/window_resize_event.hpp>

namespace comet
{
    struct WindowEvent
    {
        enum class Type
        {
            Resize,
            Close
        };

        WindowEvent(const WindowCloseEvent &window_close_event);

        WindowEvent(const WindowResizeEvent &window_resize_event);

        ~WindowEvent() = default;

        Type get_type() const;

        WindowCloseEvent as_window_close_event() const;

        WindowResizeEvent as_window_resize_event() const;

    private:
        const Type type;
        const Variant<WindowCloseEvent, WindowResizeEvent> event;
    };
}
