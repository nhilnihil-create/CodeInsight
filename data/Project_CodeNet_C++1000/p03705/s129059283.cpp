#include <algorithm>
#include <iostream>

using namespace std;

signed main() {
    long long N, A, B;
    cin >> N >> A >> B;
    long long mins = (A * 2 + N - 2) * (N - 2 + 1) / 2 + B;
    long long maxs = (B * 2 + N - 2) * (N - 2 + 1) / 2 + A;
    cout << max(maxs - mins + 1, 0ll) << endl;
    return 0;
}