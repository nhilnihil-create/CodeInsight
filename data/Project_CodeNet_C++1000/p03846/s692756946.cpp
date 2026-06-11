
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	

	ll power(ll x, ll y, ll p) {
		ll res = 1;
		x = x%p;

		if(x == 0) {
			return 0;
		}
		
		while(y>0) {
			if(y&1) {
				res = (res*x)%p;
			}
			y = y>>1;
			x = (x*x)%p;
		}
		return res;
	}
	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);

		ll n;
		cin>>n;

		vector<ll> v;

		for(ll i=0; i<n; i++) {
			ll x;
			cin>>x;
			v.push_back(x);
		}

		sort(v.begin(),v.end());
		ll tag = 0;
		if(n%2 == 0) {
			for(ll i=0; i<n; i+=2) {
				if(v[i] != i+1 || v[i+1] != i+1) {
					tag = 1;
					
					break;
				}
			}
		}
		else {
			if(v[0] != 0) {
				
				tag = 1;
			}
			else {
				for(ll i=1; i<n; i+=2) {
					if(v[i] != i+1 || v[i+1] != i+1) {
						tag = 1;
						
						break;
					}
				}
			}
		}

		if(tag == 1) {
			cout<<0<<endl;
		}
		else {
			cout<<power(2,n/2,mod)<<endl;
		}
		return 0;
	}
