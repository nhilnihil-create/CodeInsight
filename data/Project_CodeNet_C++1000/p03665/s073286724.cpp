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
    int n,p;
    cin>>n>>p;
    vector<int> a(n);
    int odd=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==1) odd++;
    }
    ll ans=pow(2,n-1);
    if(odd==0){
        if(p==0) cout<<ans*2;
        else cout<<0;
    }
    else cout<<ans;
}