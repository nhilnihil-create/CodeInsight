#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
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
    if(H%3==0 || W%3==0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1e18;
    cmin(ans, W);
    cmin(ans, H);
    REP(h,1,H){
        ll c = (H-h)*W;
        ll a = h*(W/2);
        ll b = h*(W/2 + W%2);
        ll M = max(a,max(b,c));
        ll m = min(a,min(b,c));
        cmin(ans,M-m);
    }
    swap(H,W);
    REP(h,1,H){
        ll c = (H-h)*W;
        ll a = h*(W/2);
        ll b = h*(W/2 + W%2);
        ll M = max(a,max(b,c));
        ll m = min(a,min(b,c));
        cmin(ans,M-m);
    }
    cout << ans << endl;
}