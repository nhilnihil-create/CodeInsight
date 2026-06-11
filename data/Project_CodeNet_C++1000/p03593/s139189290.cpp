#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W; cin>>H>>W;
    map<char,int> mp;
    rep(h,0,H)rep(w,0,W){
        char c; cin>>c;
        mp[c]++;
    }

    int cntT2=0,cntOdd=0;
    for(auto m:mp){
        cntOdd+=m.second%2;
        if(m.second%4>1) cntT2++;
    }

    string ans="Yes";
    if(H%2 && W%2){
        if(cntOdd>1 || cntT2>W/2+H/2) ans="No";
    }else if(H%2 || W%2){
        if(cntOdd>0 || cntT2>(H%2)*W/2+(W%2)*H/2) ans="No";
    }else{
        if(cntOdd>0 || cntT2>0) ans="No";
    }

    cout<<ans<<endl;
}