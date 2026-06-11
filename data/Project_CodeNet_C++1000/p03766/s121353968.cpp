#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;
const int maxn = 1e6 + 7;

int dp[maxn];
int suf[maxn];
int ss[maxn];

int main() {

	fill(dp,dp+maxn,0); fill(suf,suf+maxn,0); fill(ss,ss+maxn,0);

	int n; cin>>n; 
	if (n == 1) { cout<<1<<endl; return 0; }
	
	dp[n] = suf[n] = ss[n] = n-1;

	int n2 = ((long long)(n-1) * (n-1))%( (long long) md);

	for (int j = n-1; j >= 1; j--) {
		if (j == 1) dp[j] = (n + suf[2])%md;
		else dp[j] = n-1;

		dp[j] = (dp[j] + (n2 + ss[j+3])%md)%md;
		suf[j] = (suf[j+1] + dp[j])%md;
		ss[j] = (ss[j+1] + suf[j])%md;
	}

	cout<<dp[1]<<endl;
}
