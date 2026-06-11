#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;
ll dp[MAX][3];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),B(N);
    cin>>A[0];
    for(int i=1;i<N;i++){
        char c;cin>>c;
        if(c=='-') B[i]=1;
        cin>>A[i];
    }
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=-INF;
        }
    }
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        if(!B[i]){
            chmax(dp[i+1][0],dp[i][0]+A[i]);
            chmax(dp[i+1][0],dp[i][1]-A[i]);
            
            chmax(dp[i+1][1],dp[i][1]-A[i]);
            chmax(dp[i+1][1],dp[i][2]+A[i]);
            
            chmax(dp[i+1][2],dp[i][2]+A[i]);
        }else{
            chmax(dp[i+1][0],dp[i][0]-A[i]);
            
            chmax(dp[i+1][1],dp[i][0]-A[i]);
            chmax(dp[i+1][1],dp[i][1]+A[i]);
            
            chmax(dp[i+1][2],dp[i][1]+A[i]);
            chmax(dp[i+1][2],dp[i][2]+A[i]);
        }
    }
    
    ll ans=-INF;
    
    for(int j=0;j<3;j++) chmax(ans,dp[N][j]);
    
    cout<<ans<<endl;
}
