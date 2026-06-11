#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r;
        ans += r - l + 1;
    }

    cout << ans << endl;
    return 0;
}