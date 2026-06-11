#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    ll h,w;cin >> h >> w;
    ll ans=LINF;
    rrep(i,h){
        if(i==h) continue;
        ll area1=(h-i)*w;
        ll area2=i*(w/2);
        ll area3=i*((w+1)/2);
        ll mn=min({area1,area2,area3});
        ll mx=max({area1,area2,area3});
        chmin(ans,mx-mn);
    }
    rrep(i,h){
        if(i==h) continue;
        ll area1=i*w;
        ll area2=((h-i)/2)*w;
        ll area3=((h-i+1)/2)*w;
        ll mn=min({area1,area2,area3});
        ll mx=max({area1,area2,area3});
        chmin(ans,mx-mn);
    }
    rrep(i,w){
        if(i==w) continue;
        ll area1=(w-i)*h;
        ll area2=i*(h/2);
        ll area3=i*((h+1)/2);
        ll mn=min({area1,area2,area3});
        ll mx=max({area1,area2,area3});
        chmin(ans,mx-mn);
    }
    rrep(i,w){
        if(i==w) continue;
        ll area1=i*h;
        ll area2=((w-i)/2)*h;
        ll area3=((w-i+1)/2)*h;
        ll mn=min({area1,area2,area3});
        ll mx=max({area1,area2,area3});
        chmin(ans,mx-mn);
    }
    cout << ans << endl;
    return 0;
}