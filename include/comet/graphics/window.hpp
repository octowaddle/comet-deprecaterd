#pragma once

#include <comet/base/types.hpp>
#include <comet/events/event_queue.hpp>

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

        bool events_queued() const;

        Event poll_event();

    private:
        EventQueue event_queue;
        Handle handle = nullptr;
    };
}
