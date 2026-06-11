#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;

    set<pair<int,int>> setL;
    int ans=0;
    rep(n,0,N){
        int a; cin>>a;
        pair<int,int> love,loved;
        love=make_pair(n+1,a);
        loved=make_pair(a,n+1);

        if(setL.count(loved)){setL.erase(loved); ans++;}
        else setL.insert(love);
    }

    cout<<ans<<endl;
}