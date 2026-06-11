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
    rep(i,n) cin>>a[i];
    reverse(all(a));
    rep(i,n){
        if(i%2==0) b[i/2]=a[i];
        else b[n-1-i/2]=a[i];
    }
    rep(i,n) cout<<b[i]<<" ";
    cout<<endl;
}