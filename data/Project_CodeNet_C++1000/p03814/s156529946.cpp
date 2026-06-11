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
	string s;
	cin >> s;
	int a=s.size(),b=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A') a = min(a,i);
		if(s[i]=='Z') b = max(b,i);
	}
	cout << max(b-a+1,0LL);
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
