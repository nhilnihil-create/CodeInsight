#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <cmath>

#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}

int main(int argc, char const *argv[]) {
    ull N, M;
    cin >> N >> M;

    ull l = 0;
    ull u = (N + M) / 3 + 1;
    while (u - l > 1) {
        ull m = (u + l) / 2;
        // p(l, m, u);
        if (M < m*2 || N + M/2 < m*2) {
            u = m;
            // p("ng");
        } else {
            l = m;
            // p("ok");
        }
    }

    cout << l << endl;

    return 0;
}
