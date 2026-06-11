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

const int M = 1e9+7;

int answer[100001];

void work(int n)
{
	answer[1] = 1;
	for(int i=2;i<=n;i++)
	{
		answer[i] = i*(answer[i-1] % M);
		answer[i] %= M;
	}
}

void solve()
{
	int n;
	cin >> n;
	work(n);
	cout << answer[n];
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
