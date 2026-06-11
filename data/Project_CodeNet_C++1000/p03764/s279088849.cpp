#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define INF 9000000000000000000
signed main() {
    int n,m;cin>>n>>m;
    int A[n],B[m];
    rep(i,n)cin>>A[i];
    rep(i,m)cin>>B[i];
    vector<int>V1(n-1),V2(m-1);
    rep(i,n-1)V1[i]=A[i+1]-A[i];
    rep(i,m)V2[i]=B[i+1]-B[i];
    int sum1=0,sum2=0;
    rep(i,n-1){
        sum1+=V1[i]%mod*(i+1)%mod*(n-1-i)%mod;
        sum1%=mod;
    }
    rep(i,m-1){
        sum2+=V2[i]%mod*(i+1)%mod*(m-1-i)%mod;
        sum2%=mod;
    }
    cout<<sum1*sum2%mod<<endl;
    
}
        