#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define exists(s,x) (s).find(x)!=(s).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
#define fi first
#define se second
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}
inline ll modpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y&1) res = mul(res,x);
        y >>= 1;
        x = mul(x,x);
    }
    return res;
}

int main(){
    string S, T; cin >> S >> T;
    int rui1[100005];
    int rui2[100005];
    rui1[0] = 0;
    rui2[0] = 0;
    REP(i,S.size()) rui1[i+1] = rui1[i] + (S[i]=='A' ? 1:0);
    REP(i,T.size()) rui2[i+1] = rui2[i] + (T[i]=='A' ? 1:0);
    int q; cin >> q;
    while(q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int sa = rui1[b] - rui1[a-1];
        int sb = b-a+1-sa;
        int ta = rui2[d] - rui2[c-1];
        int tb = d-c+1-ta;
        if((sa+2*sb)%3==(ta+2*tb)%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}