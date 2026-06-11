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
	int n;
	cin >> n;
	int x = (n+10)/11;
	int tot = 2*x;
	int cur = x *11 +1 ;
	if(cur-n >=11) tot--;
	else if (cur-n >=6) tot--;
	cout << tot ;
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
