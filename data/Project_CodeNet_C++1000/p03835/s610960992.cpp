#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(13);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI = 3.141592653589793;

void solve()
{
	int s,k;
	cin >> k >> s;
	int ans=0;
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=k;j++)
		{
			int x = i+j;
			if(x<=s)
			{
				int cur = s-x;
				if(cur <= k) ans++;
			}
		}
	}
	cout << ans ;
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
