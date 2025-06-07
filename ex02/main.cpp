#include <iostream>
#include <list>
#include "MutantStack.hpp"

void testMutantStack()
{
    std::cout << "\n\n=== MutantStack ==========================" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n\n=== Copy test ===============================" << std::endl;
    MutantStack<int> copy = mstack;
    MutantStack<int>::iterator it2 = copy.begin();
    MutantStack<int>::iterator ite2 = copy.end();
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::cout << "\n\n=== Assignement test ===============================" << std::endl;
    MutantStack<int> mystack;
    mystack = copy;
    MutantStack<int>::iterator it3 = mystack.begin();
    while (it3 != mystack.end())
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
}

void testList()
{
    std::cout << "\n\n=== Vector ===============================" << std::endl;

    std::list<int> ls;
    ls.push_back(5);
    ls.push_back(17);
    std::cout << ls.back() << std::endl;
    ls.pop_back();
    std::cout << ls.size() << std::endl;
    ls.push_back(3);
    ls.push_back(5);
    ls.push_back(737);
    ls.push_back(0);
    std::list<int>::iterator it = ls.begin();
    std::list<int>::iterator ite = ls.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main()
{
    testList();
    testMutantStack();
    return 0;
}