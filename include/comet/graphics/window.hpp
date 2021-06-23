#pragma once

#include <comet/base/types.hpp>

namespace comet
{
    struct Window
    {
        Window(const u32 width, const u32 height, const String &title);

        Window(const Window &) = delete;

        Window(Window &&other);

        ~Window();

        Window &operator=(const Window &) = delete;

        Window &operator=(Window &&other);

        bool close_requested() const;

        void update() const;

    private:
        Handle handle = nullptr;
    };
}
