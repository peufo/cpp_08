#include "Span.hpp"

void Span::ensureIsSorted()
{
    if (!this->isSorted)
        this->values.sort();
    this->isSorted = true;
}

Span::~Span()
{
}

Span::Span() : capacity(0), isSorted(false)
{
}

Span::Span(unsigned int capacity) : capacity(capacity), isSorted(false)
{
}

Span::Span(const Span &src)
{
    this->capacity = src.capacity;
    this->values = src.values;
    this->isSorted = src.isSorted;
}

Span &Span::operator=(const Span &src)
{
    if (this == &src)
        return *this;
    this->capacity = src.capacity;
    this->values = src.values;
    this->isSorted = src.isSorted;
    return *this;
}

void Span::print()
{
    std::cout << "Span=[";
    for (std::list<int>::const_iterator i = this->values.begin(); i != this->values.end(); i++)
        std::cout << *i << ", ";
    std::cout << "\b\b]" << std::endl;
}

void Span::addNumber(int number)
{
    if (this->values.size() >= this->capacity)
        throw std::runtime_error("Span: Overflow capacity");
    this->values.push_back(number);
    this->isSorted = false;
}

int Span::shortestSpan()
{
    if (this->values.size() < 2)
        throw std::runtime_error("Span: Cannot get shortest span with less of 2 values");
    this->ensureIsSorted();
    int shortest = std::numeric_limits<int>::max();
    std::list<int>::const_iterator curr = this->values.begin();
    std::list<int>::const_iterator prev = curr++;
    while (curr != this->values.end())
    {
        int span = *curr - *prev;
        if (span < shortest)
            shortest = span;
        curr++;
        prev++;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (this->values.size() < 2)
        throw std::runtime_error("Span: Cannot get longest span with less of 2 values");
    this->ensureIsSorted();
    return this->values.back() - this->values.front();
}
