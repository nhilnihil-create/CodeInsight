/**
*    created: 30.06.2020 14:00:18
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int mod = 1000000007;
const long double pi = acos(-1.0);
const int inf = 1LL << 60;


// 素因数分解してmapに格納
map<int,int> mp;

void prime(int n) {
    if (n == 1) return;
    for (int i = 2; i*i<= n; i++) {
        if (n % i == 0) {
            prime(i);
            prime(n/i);
            return;
        }
    }
    mp[n]++;
    return;
}


signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    int n;
    cin >> n;
    rep2(i,1,n+1) {
        prime(i);
    }
    int ans = 1;
    for (auto p : mp) {
        int t = p.second + 1;
        t %= mod;
        ans *= t;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}