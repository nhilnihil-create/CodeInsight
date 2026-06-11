#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	int n,l;
	cin >> n >> l;
	string s[n];
	for(int i=0; i<n; i++)	cin >> s[i];
	sort(s,s+n);
	for(int i=0; i<n; i++)	cout << s[i];
	cout << endl;
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