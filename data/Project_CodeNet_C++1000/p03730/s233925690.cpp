#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

int gcd(int a, int b, int &x, int &y)	{
	if(b==0)	{
		x=1;
		y=0;
		return a;
	}
	int x1,y1;
	int g = gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return g;
}

void solve()	{
	int a,b,c;
	cin >> a >> b >> c;
	int x,y;
	int g = gcd(a,b,x,y);
	if(c%g==0)	cout << "YES\n";
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