#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <cmath>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

// void p() {
//     cout << "\n";
// }
// template<class Head, class... Body>
// void p(Head head, Body... body) {
//     cout << head << ",";
//     p(body...);
// }

int main(int argc, char const *argv[]) {
    int A, B;
    cin >> A >> B;
    cout << (A + B) % 24 << endl;

    return 0;
}
