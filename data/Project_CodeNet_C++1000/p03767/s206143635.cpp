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
    vector<ll> a(3*n);
    rep(i,3*n) cin>>a[i];
    sort(all(a));
    ll sum=0;
    for(int i=n;i<3*n;i+=2) sum+=a[i];
    cout<<sum;
}