#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e16;
ll h,w;
ll type1(){
    ll a = w/3;
    ll b = (w-a)/2;
    ll c = w-a-b;
    ll res = (c-a)*h;
    return res;
}

ll type2(){
    ll a = h/3;
    ll b = (h-a)/2;
    ll c = (h-a-b);
    ll res = (c-a)*w;
    return res;
}

ll type3(){
    ll res = INF;
    for(ll i=1;i<w;i++){
        ll A = h*i;
        ll a = h/2;
        ll B = (w-i)*a;
        ll C = (h-a)*(w-i);
        ll m = min(A,min(B,C));
        ll M = max(A,max(B,C));
        res = min(res,M-m);
    }
    return res;
}

ll type4(){
    ll res = INF;
    for(ll j=1;j<h;j++){
        ll A = w*j;
        ll a = w/2;
        ll B = (h-j)*a;
        ll C = (w-a)*(h-j);
        ll m = min(A,min(B,C));
        ll M = max(A,max(B,C));
        res = min(res,M-m);
    }
    return res;
}

int main(){
    cin >> h >> w;
    ll ans=type1();
    chmin(ans,type2());
    chmin(ans,type3());
    chmin(ans,type4());
    cout << ans << endl;
    return 0;
}

