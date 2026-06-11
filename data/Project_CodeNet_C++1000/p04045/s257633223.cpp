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

bool ok[10];

void solve()
{
	int n,k;
	cin>>n>>k;
	while(k--)
	{
		int x;
		cin >> x;
		ok[x] = 1;
	}
	for(int i=n;;i++)
	{
		int cur=i;
		while(cur)
		{
			int c=cur%10;
			if(ok[c]==1)
			{
				break;
			}
			cur/=10;
		}
		if(cur==0)
		{
			cout << i ;
			return ;
		}
	}
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
