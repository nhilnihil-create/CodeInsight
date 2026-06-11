#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

////////////////////////////////////////////////////////

/*
左からできる限りaにしていく
aにできないなら一個右をaにする
一番右で回数を調整
*/

int main() {
    string s; cin >> s;
    ll k; cin >> k;

    rep(i, 0, sz(s)){
        if(s[i] == 'a') continue;
        if('z'-s[i] + 1 <= k){ 
            k -= ('z'-s[i]) + 1;
            s[i] = 'a';
        }
    }
    k %= 26;
    s[sz(s)-1] += k;
    if(s[sz(s)-1] > 'z') s[sz(s)-1] -= 26;
    co(s);


    return 0;
}


