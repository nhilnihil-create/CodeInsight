#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5005,INF=1<<30;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    int M=S.size();
    
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i+1][max(0,j-1)]+=dp[i][j];
            dp[i+1][max(0,j-1)]%=mod;
            
            dp[i+1][j+1]+=2*dp[i][j];
            dp[i+1][j+1]%=mod;
        }
    }
    
    cout<<dp[N][M]*rui(rui(2,mod-2),M)%mod<<endl;
}
