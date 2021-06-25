#include <comet/events/event_queue.hpp>

namespace comet
{
    bool EventQueue::empty() const
    {
        return queue.empty();
    }

    void EventQueue::enqueue(const Event &event)
    {
        queue.emplace(event);
    }

    Event EventQueue::dequeue()
    {
        auto event = queue.front();
        queue.pop();
        return event;
    }
}
