#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    string S,T; cin>>S>>T;

    int match=0;
    rep(i,0,N){
        bool matching=true;
        rep(j,0,N-i) if(S.at(i+j)!=T.at(j)){
            matching=false;
            break;
        }
        if(matching){
            match=N-i;
            break;
        }
    }

    cout<<2*N-match<<endl;
}