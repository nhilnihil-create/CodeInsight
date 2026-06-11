#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll H,W;
    cin >> H >> W;
    if(!(H%3) || !(W%3)){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1e18;
    cmin(ans,W);
    cmin(ans,H);
    ll t1 = W/2;
    ll t2 = W - W/2;
    REP(i,1,H){
        ll M = max(W*(H-i),max(t1*i,t2*i));
        ll m = min(W*(H-i),min(t1*i,t2*i));
        cmin(ans, M-m);
    }
    t1 = H/2;
    t2 = H - H/2;
    REP(i,1,W){
        ll M = max(H*(W-i),max(t1*i,t2*i));
        ll m = min(H*(W-i),min(t1*i,t2*i));
        cmin(ans, M-m);
    }
    cout << ans << endl;
}
