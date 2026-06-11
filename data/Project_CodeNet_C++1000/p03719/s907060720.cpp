#include <iostream>
#include <vector>
#include <algorithm>
// #include <set>
// #include <string>
// #include <cmath>
// #include <map>
// #include <iomanip>

#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;
// typedef long long ll;

// void p() {
//     cout << "\n";
// }
// template<class Head, class... Body>
// void p(Head head, Body... body) {
//     cout << head << ",";
//     p(body...);
// }

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}


int main(int argc, char const *argv[]) {
    int A, B, C;
    cin >> A >> B >> C;
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
