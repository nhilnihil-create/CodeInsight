#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int sx,sy,tx,ty;cin>>sx>>sy>>tx>>ty;
    int h=ty-sy,w=tx-sx;
    vector<char> s;
    rep(i,h)cout<<"U";
    rep(i,w)cout<<"R";
    rep(i,h)cout<<"D";
    rep(i,w)cout<<"L";
    cout<<"D";
    rep(i,w+1)cout<<"R";
    rep(i,h+1)cout<<"U";
    cout<<"L";
    cout<<"U";
    rep(i,w+1)cout<<"L";
    rep(i,h+1)cout<<"D";
    cout<<"R"<<endl;
}
