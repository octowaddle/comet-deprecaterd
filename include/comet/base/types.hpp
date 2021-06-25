#pragma once

#include <string>
#include <cinttypes>
#include <stdexcept>
#include <queue>
#include <optional>
#include <variant>
#include <vector>

namespace comet
{
    using String = std::string;

    using Handle = void *;

    using u32 = std::uint32_t;

    template <typename T>
    using Queue = std::queue<T>;

    template <typename... T>
    using Variant = std::variant<T...>;

    template <typename T>
    using Optional = std::optional<T>;

    template <typename T>
    using Vector = std::vector<T>;
}
