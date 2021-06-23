#pragma once

#include <comet/base/types.hpp>

namespace comet
{
    struct Exception : public std::exception
    {
        explicit Exception(const char *description);

        explicit Exception(const String &description);

        virtual ~Exception() = default;

        virtual const char *what() const noexcept;

    private:
        const String description;
    };
}
