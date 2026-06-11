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
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2 ;
	int u = y2 - y1;
	for(int i=0;i<u;i++) cout << "U";
	int r = x2 - x1 ;
	for(int i=0;i<r;i++) cout << "R";
	for(int i=0;i<u;i++) cout << "D";
	for(int i=0;i<r;i++) cout << "L";
	cout << "L";
	u++;
	for(int i=0;i<u;i++) cout << "U";
	r++;
	for(int i=0;i<r;i++) cout << "R";
	cout << "DR";
	for(int i=0;i<u;i++) cout << "D";
	for(int i=0;i<r;i++) cout << "L";
	cout << "U";
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
