#pragma once

#include <comet/base/types.hpp>

namespace comet
{
    struct KeyPressedEvent
    {
        KeyPressedEvent(const u32 key_code);

        ~KeyPressedEvent() = default;

        u32 get_key_code() const;

    private:
        const u32 key_code;
    };
}
