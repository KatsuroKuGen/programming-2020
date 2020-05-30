#ifndef UNTITLED_ITERATOR_H
#define UNTITLED_ITERATOR_H

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

template <typename T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
    private:
        T* data;
        int position;
        int start;
        int end;
        size_t capacity;

    public:
        using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;

        Iterator(T* buffer, size_t & _capacity, int& _start, int& _end, int _position)
        {
            data = buffer;
            capacity = _capacity;
            start = _start;
            end = _end;
            position = _position;
        }

        bool operator!= (Iterator const& other_iterator) const
        {
            return this->position % capacity != other_iterator.position % capacity;
        }

        bool operator== (Iterator const& other_iterator) const
        {
            return this->position % capacity == other_iterator.position % capacity;
        }

        bool operator> (const Iterator& rhs) const
        {
            if (start > end)
            {
                if (position < capacity && rhs.position < capacity)
                {
                    return position > rhs.position;
                }
                else if (position < capacity)
                {
                    return false;
                }
                else if (rhs.position < capacity)
                {

                    return true;
                }
                else
                {
                    return position > rhs.position;
                }
            }
            else
            {
                return position > rhs.position;
            }
        }

        bool operator< (const Iterator& rhs) const
        {
            if (start > end)
            {
                if (position < capacity && rhs.position < capacity)
                {
                    return position < rhs.position;
                }
                else if (position < capacity)
                {
                    return true;
                }
                else if (rhs.position < capacity)
                {
                    return false;
                }
                else
                {
                    return position < rhs.position;
                }
            }
            else
            {
                return position < rhs.position;
            }
        }

        bool operator>= (const Iterator& rhs) const
        {
            if (start > end)
            {
                if (position < capacity && rhs.position < capacity)
                {
                    return position >= rhs.position;
                }
                else if (position < capacity)
                {
                    return false;
                }
                else if (rhs.position < capacity)
                {
                    return true;
                }
                else
                {
                    return position >= rhs.position;
                }
            }
            else
                return position >= rhs.position;
        }

        bool operator<= (const Iterator& rhs) const
        {
            if (start > end)
            {
                if (position < capacity && rhs.position < capacity)
                {
                    return position <= rhs.position;
                }
                else if (position < capacity)
                {
                    return true;
                }
                else if (rhs.position < capacity)
                {
                    return false;
                }
                else
                {
                    return position <= rhs.position;
                }
            }
            else
            {
                return position <= rhs.position;
            }
        }

        difference_type operator- (const Iterator& it) const
        {
            Iterator iterator = *this;
            iterator.position -= it.position;
            return *iterator;
        }

        difference_type operator+ (const Iterator& it) const
        {
            Iterator iterator = *this;
            iterator.position += it.position;
            return *iterator;
        }

        Iterator operator+ (const int& _pos) const
        {
            Iterator iterator = *this;
            iterator.position = (position + _pos) % capacity;
            return iterator;
        }

        Iterator operator- (const int& _pos) const
        {
            Iterator iterator = *this;
            iterator.position = (position + capacity - _pos) % capacity;
            return iterator;
        }

        Iterator operator++ ()
        {
            this->position++;
            return *this;
        }

        Iterator operator++ (int)
        {
            Iterator tmp(*this);
            operator++ ();
            return tmp;
        }

        Iterator operator-- ()
        {
            this->position--;
            return *this;
        }
        Iterator operator-- (int)
        {
            Iterator tmp(*this);
            operator-- ();
            return tmp;
        }

        typename Iterator::reference operator* () const
        {
            return data[position % capacity];
        }

};

template <typename T>
class Circular_Buffer {
public:
    Circular_Buffer(size_t _capacity) {
        element = new T[_capacity + 1];
        capacity = _capacity + 1;
        start = 0;
        _end = 0;
        count = 0;
    }

    Iterator<T> begin() {
        Iterator<T> iterator(element, capacity, start, _end, start);
        return iterator;
    }

    Iterator<T> end() {
        Iterator<T> iterator(element, capacity, start, _end, _end);
        return iterator;
    }

    void push_back(const T& val) {
        if (start % capacity - _end % capacity == 1) {
            start = (start + 1) % capacity;
        }
        else {
            count++;
        }
        element[_end % capacity] = val;
        _end = (_end + 1) % capacity;
    }

    void push_top(const T& val) {
        if (_end % capacity - start % capacity == 1 || (_end == capacity - 1 && start == 0)) {
            _end = (_end + capacity - 1) % capacity;
        }
        else {
            count++;
        }
        start = (start + capacity - 1) % capacity;
        element[start % capacity] = val;
    }

    void pop_back() {
        if (start % capacity != _end % capacity) {
            _end = (_end + capacity - 1) % capacity, count--;
        }
        else {
            std::cerr << "Buffer is empty";
        }
    }

    void pop_top() {
        if (start % capacity != _end % capacity) {
            start = (start + 1) % capacity, count--;
        }
        else {
            std::cerr << "Buffer is empty";
        }
    }

    T& operator[] (const size_t & i) const {
        return element[(start + i) % capacity];
    }

    ~Circular_Buffer() {
        delete[] element;
    }

private:
    size_t capacity;
    size_t count;
    int start;
    int _end;
    T* element;
};

#endif //UNTITLED_ITERATOR_H
