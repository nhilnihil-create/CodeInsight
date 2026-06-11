#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    string S;
    cin >> S;
    int N = sz(S);
    bool fin = true;
    rep(i, N){
        if(S[i] != S[0]) fin = false;
    }
    if(fin) {cout << 0 << endl; return 0;}
    int ans = inf;
    rep(i, 26){
        vector<char> s[N+1];
        rep(j, N) s[N].pb(S[j]);
        char x = 'a'+i;
        rep3(j, N-1, 0){
            rep(k, j){
                if(s[j+1][k+1] == x) s[j].pb(x);
                else s[j].pb(s[j+1][k]);
            }
            fin = true;
            for(auto &e: s[j]) if(e != x) fin = false;
            if(fin) chmin(ans, N-j);
        }
    }
    cout << ans << endl;
}