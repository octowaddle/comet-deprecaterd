#include <comet/exceptions/exception.hpp>

namespace comet
{
    Exception::Exception(const char *description)
    : description(description)
    {
    }

    Exception::Exception(const String &description)
    : description(description)
    {
    }

    const char *Exception::what() const noexcept
    {
        return description.c_str();
    }
}
