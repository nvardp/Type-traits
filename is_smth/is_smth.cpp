#include <iostream>
#include <type_traits>

#pragma region is_void
template<typename T>
struct is_void
{
    static const bool value = false;
};
template<>
struct is_void<void>
{
    static const bool value = true;
};
#pragma endregion


#pragma region is_bool
template<typename T>
struct is_bool
{
    static const bool value = false;
};
template<>
struct is_void<bool>
{
    static const bool value = true;
};
#pragma endregion

#pragma region is_default_constructible

namespace my {
    template <class T, typename T2 = T>
    struct is_default_constructible
    {
        static const bool value = false;
    };

    template <class T>
    struct is_default_constructible<T, decltype(T())>
    {
        static const bool value = true;
    };

    template <>
    struct is_default_constructible<void, void>
    {
        static const bool value = false;
    };

};
#pragma endregion

struct A {
    A() = default;
};
struct B {
    B() = delete;
};

int main()
{
    std::cout << my::is_default_constructible<A>::value;
    std::cout << my::is_default_constructible<B>::value;
    std::cout << my::is_default_constructible<void>::value;
    std::cout << std::is_default_constructible<A>::value;
    std::cout << std::is_default_constructible<B>::value;
    std::cout << std::is_default_constructible<void>::value;
}