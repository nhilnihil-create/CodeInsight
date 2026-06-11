#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[55][3005];
// dp[i][j] means i length and sum j
int a[55];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,av;
    scanf("%d%d",&n,&av);
    int i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[0][0] = 1;
    int j,k;
    for(i=1;i<=n;i++)
        {
        for(j=i-1;j>=0;j--)
            {
            for(k=0;k<=2500;k++)
                {
                int cur = k + a[i];
                dp[j+1][cur] += dp[j][k];
            }
        }
    }
    ll ans = 0;
   for(int len = 1; len<=n;len++)
       {
       ans += dp[len][av*len];
   }
    printf("%lld\n",ans);
    return 0;
}