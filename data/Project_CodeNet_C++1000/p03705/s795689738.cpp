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
    ll n,a,b;
    cin>>n>>a>>b;
    if(a>b) cout<<0;
    else if(n==1){
        if(a==b) cout<<1;
        else cout<<0;
    }
    else cout<<(b-a)*(n-2)+1;
}