#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int X=tx-sx;
    int Y=ty-sy;
    string S;
    rep(i,X){
        S=S+"R";
    }
    rep(i,Y){
        S=S+"U";
    }
    rep(i,X){
        S=S+"L";
    }
    rep(i,Y){
        S=S+"D";
    }
    S=S+"D";
    rep(i,X+1){
        S=S+"R";
    }
    rep(i,Y+1){
        S=S+"U";
    }
    S=S+"LU";
    rep(i,X+1){
        S=S+"L";
    }
    rep(i,Y+1){
        S=S+"D";
    }
    S=S+"R";
    cout<<S<<endl;
}