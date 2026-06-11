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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b<c||d<a) cout<<0;
    else{
        int x=max(a,c),y=min(b,d);
        cout<<y-x;
    }
}