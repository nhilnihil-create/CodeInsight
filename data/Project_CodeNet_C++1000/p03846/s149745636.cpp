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

int tab[100001];

bool odd(int n)
{
	if(tab[0]!=1) return 0;
	for(int i=2;i<n;i+=2) if(tab[i] != 2) return 0;
	return 1;
}

bool even(int n)
{
	if(tab[0]!=0) return 0;
	for(int i=1;i<n;i+=2) if(tab[i] != 2) return 0;
	return 1;
}

int power(int n)
{
	if(n==0) return 1;
	else if(n%2) return 2*(power(n/2)%M)*power(n/2)%M;
	else return power(n/2)%M * power(n/2)%M;
}

void solve()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		tab[x]++;
	}
	if((n%2==0 && even(n)) || (n%2==1 && odd(n)))
	{
		cout << power(n/2);
	}
	else cout << "0";
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
