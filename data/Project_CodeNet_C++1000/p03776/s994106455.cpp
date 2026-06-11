#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

ll fact(ll n,ll r)
{
	r = min(r,n-r);
	ll p = 1,q = 1;
	while(r)
	{
		p *= n;
		q *= r;
		--n,--r;
		ll j = __gcd(p,q);
		p/= j;
		q/= j;
	}
	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	cin>>n>>a>>b;
	ll v[n];
	long double h=0.0;
	ll ans = 0;
	for(int i = 0;i<n; i++)
		cin>>v[i];
	sort(v,v+n, greater<ll>());
	for(int i = 0;i<a ; i++)
		ans += v[i];
	ll ways=0;
	h = (double)ans/a;
	int g = count(v,v+n,v[a-1]);
	int h2 = count(v,v+a,v[a-1]);
	if(v[0]==v[a-1])
	for(int i = h2; i<=min(g,b); i++)
		ways += fact(g,i);
	else
		ways += fact(g,h2);
	cout<<fixed<<setprecision(6)<<h<<endl;
	cout<<ways<<endl;
	return 0;
}