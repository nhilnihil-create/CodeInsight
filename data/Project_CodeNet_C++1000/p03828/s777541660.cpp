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

const int M = 1e9 +7;

bool arr[1001];

vector <int> prime;

void siv()
{
	for(int i=2;i<=1001;i++)
	{
		if(arr[i]==0)
		{
			prime.push_back(i);
			for(int j=i*i;j<=1001;j+=i) arr[j]=1;
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	siv();
	int ans = 1;
	for(auto &i : prime)
	{
		int x = n, cur =0;
		while(x)
		{
			x /= i;
			cur += x;
		}
		ans *= (cur+1)%M;
		ans %= M;
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
