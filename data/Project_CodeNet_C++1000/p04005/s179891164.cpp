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
    vector<ll> a(3);
    ll ans;
    rep(i,3) cin>>a[i];
    sort(all(a));
    if(a[0]%2==1&&a[1]%2==1&&a[2]%2==1) ans=a[0]*a[1];
    else ans=0;
    cout<<ans;
}