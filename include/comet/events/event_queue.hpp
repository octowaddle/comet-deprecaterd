#pragma once

#include <comet/base/types.hpp>
#include <comet/events/event.hpp>

namespace comet
{
    struct EventQueue
    {
        EventQueue() = default;

        ~EventQueue() = default;

        bool empty() const;

        void enqueue(const Event &event);

        Event dequeue();

    private:
        Queue<Event> queue;
    };
}
