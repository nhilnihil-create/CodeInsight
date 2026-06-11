#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
// #include <set>
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


int main(int argc, char const *argv[]) {
    int N;
    ull T;
    cin >> N >> T;

    vector<ull> t(N);
    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }
    ull ans = 0;
    for (int i = 0; i < N-1; ++i) {
        ans += min(T, t[i+1] - t[i]);
    }
    ans += T;
    cout << ans << endl;
    return 0;
}
