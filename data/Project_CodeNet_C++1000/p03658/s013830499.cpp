#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> l(N);
    rep(i, N) {
        cin >> l.at(i);
    }

    sort(l.begin(), l.end(), greater<int>());

    int sum = 0;
    rep(i, K) {
        sum += l.at(i);
    }

    cout << sum << endl;

    return 0;
}