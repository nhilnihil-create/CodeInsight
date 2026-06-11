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
    int w2,h2,n,w1=0,h1=0;
    cin>>w2>>h2>>n;
    int x,y,a;
    rep(i,n){
        cin>>x>>y>>a;
        if(a==1) w1=max(w1,x);
        else if(a==2) w2=min(w2,x);
        else if(a==3) h1=max(h1,y);
        else if(a==4) h2=min(h2,y);
    }
    if(w1<w2&&h1<h2) cout<<(h2-h1)*(w2-w1);
    else cout<<0;
}