#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

int col(int r)	{
	if(r>=3200)	return -1;
	if(r>=2800)	return 1;
	if(r>=2400)	return 2;
	if(r>=2000)	return 3;
	if(r>=1600)	return 4;
	if(r>=1200)	return 5;
	if(r>=800)	return 6;
	if(r>=400)	return 7;
	if(r>=1)	return 8;
	return 0;
}

void solve()	{
	int n;
	cin >> n;
	set<int> min;
	set<int> max;
	int f=0;
	for(int i=0; i<n; i++)	{
		int x;
		cin >> x;
		int c=col(x);
		if(c==-1)	max.insert(i+1000);
		else {
			f=1;
			max.insert(c);
			min.insert(c);
		}
	}
	if(f)	cout << min.size() << " " << max.size() << endl;
	else cout << 1 << " " << max.size() << endl;
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