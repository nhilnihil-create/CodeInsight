#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int mx2=57, mx=mx2*mx2;
ll dp[mx][mx2];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,a; cin>>n>>a;
	vector<int> x(n);
	for (int i=0; i<n; i++)
		cin>>x[i];
	dp[0][0]=1;
	for (int i=0; i<n; i++)
		for (int j=mx2-2; j>=0; j--)
			for (int k=mx-1; k>=x[i]; k--)
				dp[k][j+1]+=dp[k-x[i]][j];
	ll ret=0;
	for (int i=1; i<=n; i++)
		ret+=dp[i*a][i];
	cout<<ret<<"\n";
	return 0;
}