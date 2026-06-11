#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <cmath>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;

// void p() {
//     cout << "\n";
// }
// template<class Head, class... Body>
// void p(Head head, Body... body) {
//     cout << head << ",";
//     p(body...);
// }

int main(int argc, char const *argv[]) {
    int W, a, b;
    cin >> W >> a >> b;
    if (a + W < b) {
        cout << b - (a + W) << endl;
    } else if (b + W < a) {
        cout << a - (b + W) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
