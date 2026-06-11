#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const int mod=1000000007;

int main(){
    int n;cin>>n;
    int t[n],a[n];
    rep(i,n)cin>>t[i];
    rep(i,n)cin>>a[i];
    int com[n];
    rep(i,n)com[i]=min(t[i],a[i]);
    com[0]=com[n-1]=1;
    rep(i,n-1){
        if(t[i]!=t[i+1]){
            com[i+1]=1;
            if(t[i+1]>a[i+1])com[i+1]=0;
        }
    }
    rep(i,n-1){
        if(a[i]!=a[i+1]){
            com[i]=1;
            if(a[i]>t[i])com[i]=0;
        }
    }
    ll ans=1;
    rep(i,n){
        ans*=com[i]%mod;
        ans%=mod;
    }
    cout<<ans*(t[n-1]==a[0]?1:0)<<endl;
}
