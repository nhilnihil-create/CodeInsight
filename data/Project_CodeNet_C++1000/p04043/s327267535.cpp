#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	int a,b,c;
	cin >> a >> b >> c;
	int cnt[8];
	memset(cnt,0,sizeof(cnt));
	cnt[a]++;
	cnt[b]++;
	cnt[c]++;
	if(cnt[5]==2 && cnt[7]==1)	cout << "YES\n";
	else cout << "NO\n";
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