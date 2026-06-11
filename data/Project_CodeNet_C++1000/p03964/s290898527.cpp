/* When Talent doesn't work, Hard work beats Talent*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(2);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define sp " "
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI=3.141592653589793;

void solve()
{
	int a=1,b=1;
	int n;
	cin >>n;
	while(n--)
	{
		int x,y;
		cin >> x >> y;
		int m1= (a+x-1)/x;
		int m2= (b+y-1)/y;
		int m= max(m1,m2);
		a = x*m;
		b = y*m;
		//cout << a << " " << b << nl;
	}
	cout << a+b << nl;
}

int32_t main()
{
	FastIO;
	Fast_D;
	int T;
	T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
