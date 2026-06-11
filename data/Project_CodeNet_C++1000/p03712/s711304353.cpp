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
    int h,w;
    cin>>h>>w;
    char a[h+2][w+2];
    repi(i,1,h+1){
        repi(j,1,w+1){
            cin>>a[i][j];
        }
    }
    rep(j,w+2){
        a[0][j]='#';
        a[h+1][j]='#';
    }
    rep(i,h+2){
        a[i][0]='#';
        a[i][w+1]='#';
    }
    rep(i,h+2){
        rep(j,w+2){
            cout<<a[i][j];
            if(j==w+1) cout<<endl;
        }
    }
}