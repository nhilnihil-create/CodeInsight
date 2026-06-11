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
    ll total=0;
    cin>>n;
    vector<int> t(n);
    rep(i,n){
        cin>>t[i];
        total+=t[i];
    }
    cin>>m;
    vector<int> p(m),x(m);
    rep(i,m) cin>>p[i]>>x[i];
    rep(i,m){
        ll ans=total-t[p[i]-1]+x[i];
        cout<<ans<<endl;
    }
}