#include <iostream>
#include <string>
// #include <algorithm>
// #include <numeric>
// #include <set>
// #include <cmath>
// #include <string>
// #include <map>
// #include <iomanip>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
// typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}


int main(int argc, char const *argv[]) {
    int X, A, B;
    cin >> X >> A >> B;
    if (A >= B) {
        cout << "delicious" << endl;
    } else if (B - A <= X) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }

    return 0;
}
