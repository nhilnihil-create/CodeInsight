#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    rep(i, N) {
        cin >> x.at(i);
    }

    int sum = 0;
    rep(i, N) {
        int disA = x.at(i) - 0;
        int disB = K - x.at(i);
        sum += min(disA, disB) * 2;
    }

    cout << sum << endl;

    return 0;
}