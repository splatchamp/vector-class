#include "Vector.h"
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector;

int main() {
    Vector<int> vector(5);
    vector.push_back(2);
    vector.push_back(4);
    vector.push_back(8);
    vector.push_back(3);
    vector.push_back(2);
    vector.push_back(9);

    Vector<int> other(5);
    other.push_back(2);
    other.push_back(4);
    other.push_back(8);
    other.push_back(3);
    other.push_back(2);
    other.push_back(9);

    bool result = vector == other;
    cout << result;
}
