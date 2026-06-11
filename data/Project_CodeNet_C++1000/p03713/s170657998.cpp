#include<bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(ll i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

ll max3(ll a, ll b, ll c){
    if(a >= b && a >= c)return a;
    if(b >= a && b >= c)return b;
    return c;
}

ll min3(ll a, ll b, ll c){
    if(a <= b && a <= c)return a;
    if(b <= a && b <= c)return b;
    return c;
}

int main() {
    ll h, w, ans = inf;
    cin >> h >> w;
    REP(i, h){
        ll a, b, c;
        a=i*w;b=(h-i)/2*w;c=((h-i)-(h-i)/2)*w;
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
        a=i*w;b=w/2*(h-i);c=(w-w/2)*(h-i);
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
        a=(h-i)*w;b=i/2*w;c=(i-i/2)*w;
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
        a=(h-i)*w;b=w/2*i;c=(w-w/2)*i;
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
    }
    swap(h, w);
    REP(i, h){
        ll a, b, c;
        a=i*w;b=(h-i)/2*w;c=((h-i)-(h-i)/2)*w;
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
        a=i*w;b=w/2*(h-i);c=(w-w/2)*(h-i);
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
        a=(h-i)*w;b=i/2*w;c=(i-i/2)*w;
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
        a=(h-i)*w;b=w/2*i;c=(w-w/2)*i;
        ans = min(ans, max3(a,b,c)-min3(a,b,c));
    }
    cout << ans << endl;
}