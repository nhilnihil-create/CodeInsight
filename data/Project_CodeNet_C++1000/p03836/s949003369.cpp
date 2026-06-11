#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int sx,sy,tx,ty; cin>>sx>>sy>>tx>>ty;

    string ans;
    rep(i,0,tx-sx) ans+="R";
    rep(i,0,ty-sy) ans+="U";
    rep(i,0,tx-sx) ans+="L";
    rep(i,0,ty-sy) ans+="D";

    ans+="D";
    rep(i,0,tx-sx+1) ans+="R";
    rep(i,0,ty-sy+1) ans+="U";
    ans+="LU";
    rep(i,0,tx-sx+1) ans+="L";
    rep(i,0,ty-sy+1) ans+="D";
    ans+="R";

    cout<<ans<<endl;
}