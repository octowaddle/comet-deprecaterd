#include <comet/events/window_events/window_resize_event.hpp>

namespace comet
{
    WindowResizeEvent::WindowResizeEvent(const u32 width, const u32 height)
    : width(width)
    , height(height)
    {
    }

    u32 WindowResizeEvent::get_width() const
    {
        return width;
    }

    u32 WindowResizeEvent::get_height() const
    {
        return height;
    }
}
