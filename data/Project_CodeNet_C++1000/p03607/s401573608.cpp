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
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    ll ans=0,i=0;
    while(i<n){
        ll b=a[i],c=0;
        while(i<n&&b==a[i]) c++,i++;
        ans+=c%2;
    }
    cout<<ans;
}