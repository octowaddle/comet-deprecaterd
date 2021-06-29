#include <comet/events/key_events/key_pressed_event.hpp>

namespace comet
{
    KeyPressedEvent::KeyPressedEvent(const u32 key_code)
    : key_code(key_code)
    {
    }

    u32 KeyPressedEvent::get_key_code() const
    {
        return key_code;
    }
}
