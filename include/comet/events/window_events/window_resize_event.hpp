#pragma once

#include <comet/base/types.hpp>

namespace comet
{
    struct WindowResizeEvent
    {
        WindowResizeEvent(const u32 width, const u32 height);

        ~WindowResizeEvent() = default;

        u32 get_width() const;

        u32 get_height() const;

    private:
        const u32 width;
        const u32 height;
    };
}
