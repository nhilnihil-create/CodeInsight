#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	int n;
	cin >> n;
	int a[n];
	int rec[100000];
	memset(rec,0,sizeof(rec));
	for(int i=0; i<n; i++)	{
		cin >> a[i];
		rec[a[i]]++;
		if(a[i]-1>=0)	rec[a[i]-1]++;
		if(a[i]+1<100000) rec[a[i]+1]++;
	}
	int ans=-INF;
	for(int i=0; i<100000; i++)	{
		ans=max(ans,rec[i]);
	}
	cout << ans << endl;
}

int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}