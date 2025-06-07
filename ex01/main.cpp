#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <vector>
#include "Span.hpp"

void simpleTest()
{
    std::cout << "\n\n=== Simple test ===============================" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.print();
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // expected: 2
    std::cout << "Longest:  " << sp.longestSpan() << std::endl;  // expected: 14
}

void crashTest()
{
    std::cout << "\n\n=== Crash test ================================" << std::endl;
    try
    {
        Span sp(2);
        sp.addNumber(42);
        sp.addNumber(42);
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span sp(42);
        sp.addNumber(42);
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

#define NB_VALUES 100000
void manyTest()
{
    std::cout << "\n\n=== Many values test ==========================" << std::endl;

    Span sp(NB_VALUES);
    int start = get_time();
    std::srand(start);
    for (int i = 0; i < NB_VALUES; i++)
        sp.addNumber(std::rand());
    std::cout << "Insertion of " << NB_VALUES << " values: " << get_time() - start << "ms" << std::endl;
    start = get_time();
    std::cout << "\nShortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    std::cout << "Compute of shortest and longest span: " << get_time() - start << "ms" << std::endl;
    start = get_time();
    std::cout << "\nShortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    std::cout << "Compute of shortest and longest span for two times: " << get_time() - start << "ms" << std::endl;
}

template <typename T, size_t N>
size_t size(T (&)[N])
{
    return N;
}

void addRangeTest()
{
    std::cout << "\n\n=== Add range test ==========================" << std::endl;
    int values[] = {6, 3, 23, 45, 76, -7, -11, 65, -43, 88, 0};
    std::vector<int> vect(values, values + size(values));
    Span sp(size(values));
    sp.addRange(vect.begin(), vect.end());
    sp.print();
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << std::endl;
}

int main()
{
    simpleTest();
    crashTest();
    manyTest();
    addRangeTest();
    return 0;
}