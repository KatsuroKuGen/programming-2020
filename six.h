#include <iostream>
using namespace std;

#ifndef UNTITLED_SIX_H
#define UNTITLED_SIX_H

bool predicate_all_of(int x)
{
    return x > -228;
}


bool sorting_criteria(int x, int y)
{
    return x < y - 1;
}

bool palindrome_criteria(int x, int y)
{
    return x == y;
}

template <typename iterator, typename object>
bool all_of(iterator begin, iterator end, bool (&predict)(object))
{
    for (auto i = begin; i != end; i++)
    {
        if (predict(*i))
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

template <typename iterator, typename object>
bool is_sorted(iterator begin, iterator end, bool (&criterion)(object, object))
{
    for (auto i = begin; i != end - 1; i = next(i))
    {
        auto y = next(i);
        if (criterion(*i, *y))
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

template <typename iterator, typename object>
bool is_palindrome(const iterator begin, const iterator end, bool(&palindrome_criteria)(object, object))
{
    auto it_ = begin;
    auto _it = (end - 1);
    while(it_ < _it)
    {
        if(!palindrome_criteria(*it_, *_it))
        {
            return false;
        }
        it_ = next(it_);
        _it = prev(_it);
    }

    return true;
}

#endif //UNTITLED_SIX_H
