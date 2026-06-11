#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

ll dp[55][3005];
// dp[i][j] means i length and sum j
int a[55];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
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

//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
//	
//	ll n, a, x[55], dp[55][3005];
//	cin >> n >> a;
//	for(int i=1;i<=n;i++) {
//		cin >> x[i];
//	}
//	
//	for(int i = 0; i < 55; i++)
//		for(int j = 0; j < 3005; j++)
//			dp[i][j] = 0;
//			
//	dp[0][0] = 1;
//	for(int i = 1; i <= n; i++) {
//		for(int len = i - 1; len >= 0; len--) {
//			for(int k = 0; k <= 2500; k++) {
//				int cur = k + x[i];
//				dp[len + 1][cur] = dp[len][k];
//			}
//		}
//	}
//	
//	ll ans = 0;
//	for(int len = 1; len <= n; len++) {
//		ans += dp[len][a * len];
//	}
//	
//	cout << ans << endl;
//}