#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n),c(m),d(m);
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,m) cin>>c[i]>>d[i];
    int ans;
    rep(i,n){
        ll mini=1000000000;
        rep(j,m){
            ll dx=abs(a[i]-c[j]),dy=abs(b[i]-d[j]);
            if(mini>dx+dy){
                mini=dx+dy;
                ans=j+1;
            }
        }
        cout<<ans<<endl;
    }
}