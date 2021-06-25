#include <comet/events/key_events/key_event.hpp>

namespace comet
{
    KeyEvent::KeyEvent(const u32 key_code)
    : key_code(key_code)
    {
    }

    u32 KeyEvent::get_key_code() const
    {
        return key_code;
    }
}
