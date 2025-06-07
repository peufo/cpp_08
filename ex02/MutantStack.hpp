#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
protected:
public:
    ~MutantStack();
    MutantStack();
    MutantStack(const MutantStack<T> &src);
    typedef typename MutantStack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
};

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

#endif
