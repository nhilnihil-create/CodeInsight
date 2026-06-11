#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int K, S; cin >> K >> S;
    ll ans = 0;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            if (S - i - j >= 0 && S - i - j <= K) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}