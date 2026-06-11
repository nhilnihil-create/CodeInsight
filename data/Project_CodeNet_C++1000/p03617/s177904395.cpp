#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll q, h, s, d;
    cin >> q >> h >> s >> d;
    ll n;
    cin >> n;
    
    vll price(4);
    price[0] = q;
    price[1] = min({q*2, h});
    price[2] = min({q*4, h*2, s});
    price[3] = min({q*8, h*4, s*2, d});

    ll ans = 0;
    for (int i = 3; i >= 0; i--) {
        double l = 2.0/(4-i);
        ans += (ll)(n/l) * price[i];
        n -= (ll)(n/l) * l;
    }
    cout << ans << endl; 
}