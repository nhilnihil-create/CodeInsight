#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int n,max_dist;
int arr[N],MAX[N];
int dp[N][30];

int bin_search(int l,int val) {
	for(int i=20;i>=0;i--) {
		int r = l + (1<<i);
		if(r>n) continue;
		else {
			if(arr[r] - val <= max_dist) l += (1<<i);
		}
	}
	return l;
}

main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	cin>>max_dist;
	for(int i=1;i<=n;i++) {
		int id = bin_search(i,arr[i]);
		MAX[i] = id;
	}
	for(int i=1;i<=n;i++) dp[i][0] = MAX[i];
	for(int j=1;j<=20;j++) {
		for(int i=1;i<=n;i++) {
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}
	int q;	cin>>q;
	while(q--) {
		int a,b;	cin>>a>>b;
		if(a>b) swap(a,b);
		int ans = 0;
		for(int i=20;i>=0;i--) {
			if(dp[a][i] < b) {
				ans += (1<<i);
				a = dp[a][i];
			}
		}
		cout<<ans+1<<endl;
	}
}