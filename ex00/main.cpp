#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>

// void noCompileBecauseNoCastable()
// {
//     std::string values[] = {"Bob", "Alice"};
//     std::vector<std::string> vect(values, values + size(values));
//     std::string res = easyfind(vect, 42);
// }

template <typename T, size_t N>
size_t size(T (&)[N])
{
    return N;
}

int main(void)
{
    int values[] = {2, 6, 8, 9};
    std::vector<int> vect(values, values + size(values));
    std::list<int> ls(values, values + size(values));

    double valuesAsdouble[] = {2.4, 2.6, 6.7, 8.0, 9.5};
    std::deque<double> deq(valuesAsdouble, valuesAsdouble + size(valuesAsdouble));

    try
    {
        int resVect = easyfind(vect, 2);
        std::cout << "Find in vector: " << resVect << std::endl;

        int resList = easyfind(ls, 8);
        std::cout << "Find in list: " << resList << std::endl;

        double resDeque = easyfind(deq, 9);
        std::cout << "Find in deque: " << resDeque << std::endl;

        easyfind(deq, 42);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Oops! " << e.what() << '\n';
    }
}