#ifndef CIRCULARITERATOR_H
#define CIRCULARITERATOR_H

#include <list>
#include <iterator>
#include <cassert>
#include "CityEntity.h"

class CircularIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = CityEntity*;
    using difference_type   = std::ptrdiff_t;
    using pointer           = CityEntity**;
    using reference         = CityEntity*&;

    using container_type    = std::list<CityEntity*>;
    using inner_it          = container_type::iterator;

private:
    container_type* container_;
    inner_it it_;

public:
    explicit CircularIterator(container_type& lst)
        : container_(&lst), it_(lst.begin()) {}

    CircularIterator(container_type& lst, inner_it pos)
        : container_(&lst), it_(pos) {
        if (!container_->empty() && it_ == container_->end())
            it_ = container_->begin();
    }

    reference operator*() const {
        assert(container_ && !container_->empty());
        return const_cast<reference>(*it_);
    }

    // prefix ++
    CircularIterator& operator++() {
        if (container_->empty()) return *this;
        ++it_;
        if (it_ == container_->end())
            it_ = container_->begin();
        return *this;
    }

    // postfix ++
    CircularIterator operator++(int) {
        CircularIterator tmp(*this);
        ++(*this);
        return tmp;
    }

    // prefix --
    CircularIterator& operator--() {
        if (container_->empty()) return *this;
        if (it_ == container_->begin())
            it_ = container_->end();
        --it_;
        return *this;
    }

    // postfix --
    CircularIterator operator--(int) {
        CircularIterator tmp(*this);
        --(*this);
        return tmp;
    }

    bool operator==(const CircularIterator& other) const {
        return container_ == other.container_ && it_ == other.it_;
    }
    bool operator!=(const CircularIterator& other) const {
        return !(*this == other);
    }
};

#endif // CIRCULARITERATOR_H
