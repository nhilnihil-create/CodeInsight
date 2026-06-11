#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000005,INF=1<<30;
ll dp[MAX],sum[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    dp[1]=N;
    dp[2]=N*N%mod;
    
    sum[1]=N;
    sum[2]=N+N*N%mod;
    
    for(ll i=3;i<=N;i++){
        dp[i]=dp[i-1]+sum[i-3]+(N-1-(i-3))*N+(i-3)*(N-1);
        dp[i]%=mod;
        
        sum[i]=sum[i-1]+dp[i];
        sum[i]%=mod;
    }
    
    //for(int i=1;i<=N;i++) cout<<dp[i]<<" ";
    
    cout<<dp[N]<<endl;
}
