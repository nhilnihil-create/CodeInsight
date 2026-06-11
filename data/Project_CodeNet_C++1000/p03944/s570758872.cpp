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
	int W,H,N;
	cin >> W >> H >> N ;
	int x1=0,x2=W,y1=0,y2=H;
	while(N--)
	{
		int x,y,a;
		cin >> x >> y >> a;
		if(a==1)
		{
			x1 = max(x1,x);
		}
		if(a==2)
		{
			x2 = min(x2,x);
		}
		if(a==3)
		{
			y1 = max(y1,y);
		}
		if(a==4)
		{
			y2 = min(y2,y);
		}
	}
	int wi = max(0LL,x2-x1);
	int hi = max(0LL,y2-y1);
	cout << wi * hi ;
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
