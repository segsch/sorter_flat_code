#include <cassert>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

namespace sorter { // create this namespace in module sorter
    // Place under module sorter interface
    std::vector<int> get_sorted_copy(std::vector<int>);

    // Place under module sorter implementation
    std::vector<int> get_sorted_copy(std::vector<int> vec) {
        std::ranges::sort(vec);
        return vec;
    }
}

int main() {
    std::vector v = { 1,4,5,3,4,55,66,12,42 };
    std::vector sorted = sorter::get_sorted_copy(v);
    std::ranges::copy(sorted, std::ostream_iterator<int>{std::cout, ", "});
    std::ranges::sort(v);
    assert(sorted == v);
}