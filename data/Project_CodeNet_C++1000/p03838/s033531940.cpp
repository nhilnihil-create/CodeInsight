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
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    if((x>=0&&y>0)||(x<0&&y<=0)){
        if(x<=y) ans=abs(y-x);
        else ans+=abs(y-x)+2;
    }
    else ans=abs(abs(y)-abs(x))+1;
    cout<<ans;
}