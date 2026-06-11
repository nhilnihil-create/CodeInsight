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
    map<ll, int> m;
    for (int i = 0; i < N; i++) {
        ll a; scanf("%lld", &a);
        m[a * (-1)]++;
    }

    ll ans = 0;
    bool flag = false;
    for (auto p : m) {
        ll a = p.first * (-1);
        int num = p.second;
        if (flag) {
            if (num > 1) {
                ans *= a;
                break;
            }
        } else {
            if (num > 1) {
                if (num > 3) {
                    ans = a * a;
                    break;
                }
                ans = a;
                flag = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}