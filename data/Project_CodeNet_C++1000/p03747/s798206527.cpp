#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
#define f first
#define s second

const int N = 2e5 + 100;
const int mod = 1e9 + 7;
const ll inf = 1e17;

vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);	
	
	ll n, l, t;
	cin >> n >> l >> t;
	ll k = 0;
	for(int i = 0; i < n; i++)
	{
		ll x, w;
		cin >> x >> w;
		
		if(w == 1)
		{
			ll y = l-x;
			ll t2 = t - y;
			if(t2 >= 0)
			{
				k += 1 + t2/l;
				k = (k + n)%n;
				//cout << i << ' ' << 1 + t2/l << endl;
			}
			v.push_back((x+t)%l);
		}
		else
		{
			ll y = x+1;
			ll t2 = t - y;
			if(t2 >= 0)
			{
				k -= 1 + t2/l;
				k = (k + n*(k/n+1))%n;
				//cout << i << ' ' << 1 + t2/l << endl;
			}
			
			ll tmp = x - t + l*(t/l + 1);
			v.push_back(tmp%l);
		}
		
	}
	
	sort(v.begin(), v.end());
	
	for(ll i = k; i < n; i++)
		cout << v[i] << endl;
	for(ll i = 0; i < k; i++)
		cout << v[i] << endl;
	
	
	
	
	
	
	return 0;
}






