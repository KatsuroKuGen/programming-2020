#ifndef UNTITLED_SIXTH_H
#define UNTITLED_SIXTH_H

#include <iterator>

class IsEven {
public:
    bool operator() (int x) {
        return x % 2 == 0;
    }
};

class IsOdd {
public:
    bool operator()(int i)
    {
        return i % 2 == 1;
    }
};

class Point {
private:
    double x, y;
public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    bool operator==(const Point &p) const {
        return (x == p.getX()) and (y == p.getY());
    }
};

class Comparator {
public:
    bool operator()(Point p) {
        return p == Point(0, 0);
    }
};

template <class T>
bool is_equals(T x, T y) {
    return x == y;
}


template <class T, class Predicate>
bool any_of(T obj, Predicate p) {
    typename T::const_iterator it = obj.begin();
    while (it != obj.end()) {
        if (p(*it))
            return true;
        ++it;
    }
    return false;
}

template <class T, class Predicate>
bool is_partitioned(T first,T last, Predicate pred)
{
    while (first != last && pred(*first)) {
        ++first;
    }
    while (first != last) {
        if (pred(*first)) return false;
        ++first;
    }
    return true;
}

template <class T, class U>
bool is_palindrome(T obj, bool (*compare)(U o1, U o2)) {
    typename T::const_iterator it = obj.begin();
    typename T::const_iterator it_end = obj.end() - 1;
    while (it < it_end) {
        if (!compare(*it, *it_end)) {
            return false;
        }
        ++it;
        --it_end;
    }
    return true;
}

#endif //UNTITLED_SIXTH_H
