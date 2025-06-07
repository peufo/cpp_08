#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <stdexcept>
#include <iostream>
#include <limits>

class Span
{
private:
    std::list<int> values;
    unsigned int capacity;
    bool isSorted;
    void ensureIsSorted();

public:
    ~Span();
    Span();
    Span(unsigned int capacity);
    Span(const Span &src);
    Span &operator=(const Span &src);
    void print();
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    template <typename T>
    void addRange(T start, T end);
};

template <typename T>
void Span::addRange(T start, T end)
{
    while (start != end)
        this->addNumber(*(start++));
}

#endif
