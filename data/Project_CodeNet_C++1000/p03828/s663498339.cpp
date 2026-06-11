#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
	llint n;
	cin >> n;
	llint dp[n+1];
	memset(dp,0,sizeof(dp));
	for(llint i=1;i<=n;i++){
		llint t=i;
		for(llint j=2;j<=n;j++){
			while(t%j==0){
				dp[j]++;
				t/=j;
			}
		}
	}
	llint ans=1;
	for(llint i=2;i<=n;i++){
		ans*=(dp[i]+1);
		ans%=mod;
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
