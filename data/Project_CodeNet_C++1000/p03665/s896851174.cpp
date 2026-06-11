#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N,P; cin >> N >> P;
    ll a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    ll dp[N+1][N*100+1]={};
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=N*100;j++){
            dp[i+1][j]+=dp[i][j];
            if(j+a[i]<=100*N){
                dp[i+1][j+a[i]]+=dp[i][j];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=N*100;i++){
        if(dp[N][i]>0&&i%2==P) ans+=dp[N][i];
    }
    cout << ans << endl;
}
