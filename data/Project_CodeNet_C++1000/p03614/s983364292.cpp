#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> p(N);
    for (auto &x : p) cin >> x;

    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (p.at(i) == i + 1) {
            swap(p.at(i), p.at(i + 1));
            ans++;
        }
    }
    if (p.back() == N) ans++;

    cout << ans << endl;

    return 0;
}