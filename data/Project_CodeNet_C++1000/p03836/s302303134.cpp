#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
typedef long long ll;

signed main(){
    ll sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    tx-=sx;ty-=sy;
    sx=sy=0;
    string ans;
    rep(i,ty)ans.push_back('U');
    rep(i,tx)ans.push_back('R');
    rep(i,ty)ans.push_back('D');
    rep(i,tx)ans.push_back('L');
    ans.push_back('L');
    rep(i,ty+1)ans.push_back('U');
    rep(i,tx+1)ans.push_back('R');
    ans.push_back('D');
    ans.push_back('R');
    rep(i,ty+1)ans.push_back('D');
    rep(i,tx+1)ans.push_back('L');
    ans.push_back('U');
    cout<<ans<<endl;
}