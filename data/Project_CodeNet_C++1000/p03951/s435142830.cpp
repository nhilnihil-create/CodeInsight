#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
string s,t;


int main(){
    cin>>n>>s>>t;
    int ans=2*n;
    rep(i,1,n+1){
        string ss=s.substr(n-i,i);
        string tt=t.substr(0,i);
        if(ss==tt) chmin(ans,2*n-i);
    }
    cout<<ans<<"\n";
    return 0;
}
