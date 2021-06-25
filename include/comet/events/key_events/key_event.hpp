#pragma once

#include <comet/base/types.hpp>

namespace comet
{
    struct KeyEvent
    {
        KeyEvent(const u32 key_code);

        ~KeyEvent() = default;

        u32 get_key_code() const;

    private:
        const u32 key_code;
    };
}
