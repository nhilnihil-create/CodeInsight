#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int INF=55;
ll dp [INF] [INF * INF]; // int prevent explosion
int main()
{
    int n,a;
    cin>>n>>a;
    int x;
    dp[0][0]=1;
    for(int i=1; i<=n; i++){
        cin>>x;
        for(int j=i-1; j>=0; j--){
            for(int k=0; k<=INF*j; k++){   
                dp[j+1][k+x]+=dp[j][k];
            }
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        ans+=dp[i][i*a];
    }
    cout<<ans<<endl;
    return 0;
}