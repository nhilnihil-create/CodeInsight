#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define INF (1LL<<60)

ll dp[200010];
ll dp2[200010];

int main(){
	int n,m;
	cin >> n >> m;
	vector<int>a(n);
	rep(i,n)cin >> a[i],a[i]--;
	ll sm = 0;
	rep(i,n-1){
		if(a[i]<a[i+1]){
			sm += a[i+1]-a[i];
			dp[a[i]+2]++;
			dp[a[i+1]+1]--;
			dp2[a[i+1]+1] -= a[i+1]-a[i]-1;  
		}else{
			sm += m+a[i+1]-a[i];
			dp[a[i]+2]++;
			dp[m+a[i+1]+1]--;
			dp2[m+a[i+1]+1] -= m+a[i+1]-a[i]-1; 
		}
	}
	rep(i,2*m+2){
		dp[i+1] += dp[i];
		dp2[i] += dp[i];
		dp2[i+1] += dp2[i];
	}
	ll mx = 0;
	// rep(i,2*m){
	// 	cerr << dp[i] << " ";
	// }
	// cerr << endl;
	// rep(i,2*m){
	// 	cerr << dp2[i] << " ";
	// }
	// cerr << endl;
	rep(i,m){
		mx = max(mx,dp2[i]+dp2[i+m]);
		//cerr << sm-dp2[i]-dp2[i+m] << "  " << dp2[i] << " " << dp2[i+m] << endl;
	}
	cout << sm-mx << endl;
	return 0;
}