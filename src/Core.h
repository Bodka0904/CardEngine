#pragma once
namespace Dot{

    template <typename E>
    constexpr auto ToUnderlying(E e) noexcept
    {
        return static_cast<std::underlying_type_t<E>>(e);
    }
}