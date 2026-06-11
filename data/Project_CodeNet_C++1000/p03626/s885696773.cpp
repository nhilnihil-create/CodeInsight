#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll mod = 1e9+7;

int main(){
    
    int n;
    cin >> n;
    V<string> s(2);
    rep(i,2) cin >> s[i];

    ll ans = 1;
    int idx;
    if(s[0][0] == s[1][0]) ans = 3, idx = 1;
    else ans = 6, idx = 2;

    while(idx < n) {
        if(s[0][idx] == s[1][idx]) {
            if(s[0][idx-1] == s[1][idx-1]) ans *= 2, ans %= mod;
            else ans *= 1, ans %= mod;
            idx++;
        }
        else {
            if(s[0][idx-1] == s[1][idx-1]) ans *= 2, ans %= mod;
            else ans *= 3, ans %= mod;
            idx += 2;
        }
    }

    cout << ans << endl; 
}