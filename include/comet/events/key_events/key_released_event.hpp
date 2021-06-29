#pragma once

#include <comet/base/types.hpp>

namespace comet
{
    struct KeyReleasedEvent
    {
        KeyReleasedEvent(const u32 key_code);

        ~KeyReleasedEvent() = default;

        u32 get_key_code() const;

    private:
        const u32 key_code;
    };
}
