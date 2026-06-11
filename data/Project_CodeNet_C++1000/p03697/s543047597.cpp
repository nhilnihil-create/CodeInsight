#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
// #include <cmath>
// #include <string>
// #include <map>
// #include <iomanip>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}

template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << "{";
    for (const auto& i : s) {
        os << i << " ";
    }
    os << "}";
    return os;
}


int main(int argc, char const *argv[]) {
    int A, B;
    cin >> A >> B;
    if (A+B < 10) {
        cout << A+B << endl;
    } else {
        cout << "error" << endl;
    }

    return 0;
}
