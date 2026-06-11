#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,r;
	cin>>n>>m>>r;
	int R[r];
	for(int i = 0; i<r; i++)
	{
		cin>>R[i];
		--R[i];
	}
	sort(R,R+r);
	ll sp[n][n];
	// memset(sp,0x3f,sizeof(sp));
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			sp[i][j] = (ll)1e12;
		sp[i][i] = 0;
	}
	for(int i= 0 ; i<m; i++)
	{
		ll j,k,l;
		cin>>j>>k>>l;
		--j,--k;
		sp[j][k] = min(sp[j][k],l);
		sp[k][j] = min(sp[k][j],l);
	}
	for(int k = 0; k<n; k++)
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				sp[i][j] = min(sp[i][j],sp[i][k]+sp[k][j]);
	ll ans = 1e18, ans2 = 0;
	do
	{
		ans2 = 0;
		for(int j = 0; j<r-1; j++)
			ans2 += sp[R[j]][R[j+1]];
		ans = min(ans,ans2);
	}while(next_permutation(R,R+r));
  	cout<<ans<<endl;
	return 0;
}