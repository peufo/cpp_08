#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::value_type &easyfind(T &container, int value)
{
    for (typename T::iterator i = container.begin(); i != container.end(); i++)
    {
        if (static_cast<int>(*i) == value)
            return *i;
    }
    throw std::runtime_error("Value not found");
}

#endif
