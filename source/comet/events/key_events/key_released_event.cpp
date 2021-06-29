#include <comet/events/key_events/key_released_event.hpp>

namespace comet
{
    KeyReleasedEvent::KeyReleasedEvent(const u32 key_code)
    : key_code(key_code)
    {
    }

    u32 KeyReleasedEvent::get_key_code() const
    {
        return key_code;
    }
}
