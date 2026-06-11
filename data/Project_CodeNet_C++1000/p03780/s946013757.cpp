#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
int n,k;
int a[100000];
bool dp[10000][10000];

bool C(int m) {
	REP(i,k) {
		dp[0][i] = false;
	}

	dp[0][0] = true;


	FOR(i,1,n + 1) {
		REP(j,k) {
			if(i - 1 != m) {
				bool c = false;
				if(j - a[i - 1] >= 0) {
					c = dp[i - 1][j - a[i - 1]];
				}
				dp[i][j] = (c || dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	bool ret = false;
	if(k - a[m] < 0) {
		ret = true;
	}else {
		FOR(i,max(k - a[m],0),k) {
			ret |= dp[n][i];
		}
	}
	return ret;
}

ll binsearch_i_min(){
	ll lb = -1,ub = n;//(lb,ub]が探索範囲

	while(ub - lb > 1){
		ll mid = (lb + ub) / 2;
		if(C(mid))ub = mid;
		else lb = mid;
	}

	return ub;
}

int main(){
	cin >> n >> k;
	REP(i,n) {
		cin >> a[i];
	}
	sort(a,a+n);
	cout << binsearch_i_min() << endl;
	return 0;
}
