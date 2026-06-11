#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],b[200005],dp[200005];
main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	stack<int> q;
	q.push(0);
	for (int i = 1;  i<= n; i++){
		cin >> a[i];
		while (!q.empty() && a[q.top()] > a[i])
		{
			q.pop();
		}
		b[i] = q.top();
		q.push(i);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = dp[b[i]] + 1ll*a[i]*(i - b[i]);
		ans += dp[i];		
	}
cout<< ans;
		
}