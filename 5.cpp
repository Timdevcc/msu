#include <iostream>
#include <array>
#include <list>

template <class A, class Comp>
void selection_sort(A first, A last, Comp comp) {
    for (A i = first; i != last; ++i) {
        A min_it = i;

        for (A j = i; j != last; ++j) {
            if (comp(*j, *min_it)) {
                min_it = j;
            }
        }

        std::iter_swap(i, min_it);
    }
}

int main() {
   
}
    

