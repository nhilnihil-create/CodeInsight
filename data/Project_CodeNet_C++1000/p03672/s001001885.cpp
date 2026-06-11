#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	string s;
	cin >> s;
	int n = s.size();
	for(int i=n-2; i>=0; i--)	{
		if(i&1)	{
			//cout << s.substr(0,i/2+1) << " " << s.substr(i/2+1,i/2+1) << endl;
			if(s.substr(0,i/2+1) == s.substr(i/2+1,i/2+1))	{
				cout << i+1 << endl;
				return;
			}
		}
	}
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