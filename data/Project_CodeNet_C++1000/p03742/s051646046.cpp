#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;
    cout << (abs(X - Y) <= 1 ? "Brown" : "Alice") << '\n';
}
