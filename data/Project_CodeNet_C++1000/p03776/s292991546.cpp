#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

ll NcR(ll n, ll r) 
{ 
	ll p = 1, k = 1; 
	if (n - r < r) 
		r = n - r; 

	if (r != 0) { 
		while (r) { 
			p *= n; 
			k *= r; 
			ll m = __gcd(p, k); 
			p /= m; 
			k /= m; 

			n--; 
			r--; 
		}
	} 

	else
		p = 1; 

	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	cin>>n>>a>>b;
	ll v[n];
	long double h=0.0,g;
	for(int i = 0;i<n; i++)
		cin>>v[i];
	sort(v,v+n, greater<ll>());
	ll ans = 0,ways=1,aw = 0;
	vector<ll> c;
	set<ll>s;
	for(int i= 0; i<b; i++)
	{
		c.push_back(v[i]);
		s.insert(v[i]);
		if(i<a-1)
			ans += v[i];
		else
		{
			ans += v[i];
			g = ((long double)ans)/(i+1);
			ways = 1;
			for(auto it:s)
			{
				ll g2 = count(c.begin(),c.end(),it);
				ll y = count(v,v+n,it);
				// cout<<g2<<" "<<y<<" ";
				if(g2!=y)
					ways *= NcR(y,g2);
				// cout<<ways<<endl;
			}
			if(g==h) aw = aw+ways;
			if(g>h)
			{
				aw = ways;
				h = g;
			}
		}
	}
	cout<<fixed<<setprecision(6)<<h<<endl;
	cout<<aw<<endl;
	return 0;
}