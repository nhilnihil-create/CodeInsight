#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <iomanip>
#include <queue>
#include <string.h>
#include <bitset>

#define ll long long int
#define ld long double
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep1(i,n) for(int i = 1;i < n;i++)
#define co(x) cout << x << endl
#define cosp(x) cout << x << " "
#define all(x) x.begin(),x.end()
#define allr(x) x.begin(),x.end(),greater<int>()
#define P pair<ll,ll>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1ll << 60
#define PI 3.14159265359

using namespace std;

int main(){
	int n,ma,mb;
	cin >> n >> ma >> mb;
	vector<int> a(n),b(n),c(n);
	int a1,b1,c1;
	for(int i = 0;i < n;i++){
		cin >> a1 >> b1 >> c1;
		a[i] = a1;
		b[i] = b1;
		c[i] = c1;
	}
	ll dp[n+1][401][401];
	rep(i,n+1){
		rep(j,401){
			rep(k,401){
				dp[i][j][k] = 10000;
			}
		}
	}
	dp[0][0][0] = 0;
	for(int i = 1;i <= n;i++){
		rep(j,401){
			rep(k,401){
				if(j-a[i-1] >= 0 && k - b[i-1] >= 0){
					dp[i][j][k] = min(dp[i-1][j-a[i-1]][k-b[i-1]]+c[i-1],dp[i][j][k]);
				}
				dp[i][j][k] = min(dp[i-1][j][k],dp[i][j][k]);
			}
		}
	}
	ll ans = 10000;
	for(int i = 1;ma*i < 401 && mb*i < 401;i++){
		ans = min(ans,dp[n][ma*i][mb*i]);
	}
	if(ans == 10000) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}