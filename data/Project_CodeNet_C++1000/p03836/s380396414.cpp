#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    int sx,sy,tx,ty;cin>>sx>>sy>>tx>>ty;
    int x=tx-sx;
    int y=ty-sy;
    rep(i,y) cout<<"U";
    rep(i,x) cout<<"R";
    rep(i,y) cout<<"D";
    rep(i,x) cout<<"L";
    cout<<"L";
    rep(i,y+1) cout<<"U";
    rep(i,x+1) cout<<"R";
    cout<<"D"<<"R";
    rep(i,y+1) cout<<"D";
    rep(i,x+1) cout<<"L";
    cout<<"U";
    cout<<endl;
}