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

using namespace std;

int dp[100010][18];

int main(){
	int n;
	cin >> n;
	vector<int>x(n);
	rep(i,n)cin >> x[i];
	int l,q;
	cin >> l >> q;
	for(int k=0;k<18;k++){
		if(k==0){
			for(int i=0;i<n;i++){
				int p = lower_bound(x.begin(),x.end(),x[i]+l+1)-x.begin()-1;
				dp[i][0] = p;	
				//cerr << i << " " << p << endl;
			}
		}else{
			for(int i=0;i<n;i++){
				dp[i][k] = dp[dp[i][k-1]][k-1];
			}
		}
	}
	rep(zz,q){
		int a,b;
		cin >> a >> b;
		a--;b--;
		if(a>b)swap(a,b);
		int ans = 0;
		for(int k=17;k>=0;k--){
			if(dp[a][k]<b){
				ans += 1<<k;

				//cerr << a << " " << (1<<k) << " " << dp[a][k] << endl;
				a = dp[a][k];
			}
		}
		cout << ans+1 << endl;
	}
	return 0;
}