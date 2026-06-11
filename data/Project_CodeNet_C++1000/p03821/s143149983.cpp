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
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        if((a[i]+ans)%b[i]!=0) ans+=b[i]-(a[i]+ans)%b[i];
    }
    cout<<ans;
}