#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;



int dp[45][405][405];

int main(void){
    int n,ma,mb;
    cin>>n>>ma>>mb;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
    for(int i=0;i<45;i++){
        for(int j=0;j<405;j++){
            for(int k=0;k<405;k++){
                dp[i][j][k]=100000000;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<405;j++){
            for(int k=0;k<405;k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(j>=a[i-1] && k>=b[i-1]){
                    dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-a[i-1]][k-b[i-1]]+c[i-1]);
                }
            }
        }
    }
    int ans = 1000000000;
    for(int i=1;i<405;i++){
        for(int j=1;j<405;j++){
            if(mb*i == ma*j){
                ans = min(ans,dp[n][i][j]);
            }
        }
    }
    if(ans == 100000000)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}