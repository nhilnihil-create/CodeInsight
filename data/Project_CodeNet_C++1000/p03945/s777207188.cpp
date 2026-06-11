#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    int ans=-1;
    char preC;
    rep(i,0,S.size()){
        char c=S.at(i);
        if(preC!=c){
            preC=c;
            ans++;
        }
    }

    cout<<ans<<endl;
}