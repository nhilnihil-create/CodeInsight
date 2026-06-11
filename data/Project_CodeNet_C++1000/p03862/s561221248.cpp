/* When Talent doesn't work, Hard work beats Talent*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

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
	int n,x;
	cin >> n >>x;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int ans =0;
	for(int i=1;i<n;i++)
	{
		int cur = a[i] + a[i-1];
		if(cur <= x) continue;
		int extra = cur - x;
		ans += extra ;
		if(extra<=a[i]) a[i]-=extra;
		else a[i] = 0;
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
