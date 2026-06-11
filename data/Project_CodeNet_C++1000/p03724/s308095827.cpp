#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M; cin>>N>>M;
    vector<int> Q(N,0);
    rep(m,0,M){
        int a,b; cin>>a>>b;
        Q.at(a-1)++;
        Q.at(b-1)++;
    }

    string ans="YES";
    for(auto q:Q){
        if(q%2) ans="NO";
    }

    cout<<ans<<endl;
}