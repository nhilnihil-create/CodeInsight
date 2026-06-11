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
    char c[h][w],ans[2*h][w];
    rep(i,h){
        rep(j,w){
            cin>>c[i][j];
        }
    }
for(int i=0;i<2*h;i++){
        for(int j=0;j<w;j++){
            ans[i][j]=c[i/2][j];
        }
    }
    rep(i,2*h){
        rep(j,w){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}