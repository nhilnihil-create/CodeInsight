#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n, m;

int main() {
    cin >> n >> m;
    map<int, int> mcnt;
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        mcnt[a]++; mcnt[b]++;
    }

    bool flg = true;
    for(auto x : mcnt) {
        if(x.second % 2 != 0) {
            flg = false;
            break;
        }
    }

    if(flg) cout << "YES" << endl;
    else cout << "NO" << endl;
}