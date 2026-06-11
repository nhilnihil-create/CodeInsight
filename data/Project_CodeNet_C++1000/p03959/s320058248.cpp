#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<(n); i++)
#define int long long
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000000
using namespace std;
signed main(void){
    int n;cin>>n;
    vector<int>T(n),A(n);
    rep(i,n)cin>>T[i];rep(i,n)cin>>A[i];
    int l=0,r=n-1;
    rep(i,n-1){
        if(T[n-i-1]>T[n-i-2]){l=n-i-1;break;}
    }
    rep(i,n-1){
        if(A[i+1]<A[i]){r=i;break;}
    }
    if(T[n-1]!=A[0] || l>r)cout<<0<<endl;
    else {
        int ans=1;
        rep(i,r-1){
            if(T[i+1]>T[i])continue;
            ans=ans*T[i+1]%mod;
        }
        for(int i=n-1;i>r;i--){
            if(A[i-1]>A[i])continue;
            ans=ans*A[i-1]%mod;
        }
        cout<<ans<<endl;
    }
    
}
