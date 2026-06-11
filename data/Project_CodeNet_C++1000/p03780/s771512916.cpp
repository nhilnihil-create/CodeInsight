#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

int a[5555],cnt[5555];
bool dp[2][5555][5555];

int main(void){
	int n,k,i,j,ans=0,l,r;
	fill(dp[0][0],dp[2][0],false);
	bool flag;
	dp[0][0][0] = true;
	cin >> n >> k;
	dp[1][n][0] = true;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	for(i=0; i<n; ++i){
		for(j=0; j<=k; ++j){
			if(dp[0][i][j]){
				dp[0][i+1][j] = true;
				if(j+a[i]<=k){
					dp[0][i+1][j+a[i]] = true;
				}
			}
		}
	}
	for(i=n; i>0; --i){
		for(j=0; j<=k; ++j){
			if(dp[1][i][j]){
				dp[1][i-1][j] = true;
				if(j+a[i-1]<=k){
					dp[1][i-1][j+a[i-1]] = true;
				}
			}
		}
	}
	for(i=0; i<n; ++i){
		cnt[0] = 1;
		for(j=1; j<=k; ++j){
			cnt[j] = cnt[j-1];
			if(dp[1][i+1][j]){
				++cnt[j];
			}
		}
		flag = true;
		for(j=0; j<=k; ++j){
			if(!dp[0][i][j]){
				continue;
			}
			r = k - j - 1;
			l = r - a[i];
			if(r < 0){
				continue;
			}else if(l < 0){
				if(cnt[r]){
					flag = false;
					break;
				}
			}else if(cnt[r]-cnt[l]){
				flag = false;
				break;
			}
		}
		if(flag){
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}

