#include <bits/stdc++.h>
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;
 
ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
ll mod(ll a, ll b) {return (a % b + b) % b;}
using namespace std;

int main()
{
	fast;
	ll h,w;
  	cin >> h >> w;
  	if (h % 3 == 0 || w % 3 == 0)
  	{
    	cout << 0 << endl;
  	}
  	else
  	{
    	ll ans = INT_MAX;
    	for (ll i = 1; i < h; i++)
    	{
      		ll x1 = i*w;
      		ll x2 = (h - i) * (w / 2);
      		ll x3 = (h - i) * (w - w / 2);
      		ll y2 = (h - i) / 2 * w;
      		ll y3 = ((h - i) - (h - i) / 2) * w;
      		ans = min(ans, max(x1, max(x3, x2)) - min(x1, min(x3, x2)));
      		ans = min(ans, max(x1, max(y3, y2)) - min(x1, min(y3, y2)));
    	}
	    for (ll i = 1; i < w; i++)
	    {
	      	ll x1 = i * h;
	      	ll x2 = (w - i) * (h / 2);
	      	ll x3 = (w - i) * (h - h / 2);
	     	ll y2 = (w - i) / 2 * h;
	      	ll y3 = ((w - i) - (w - i) / 2) * h;
	      	ans = min(ans, max(x1, max(x3, x2)) - min(x1, min(x3, x2)));
	      	ans = min(ans, max(x1, max(y3, y2)) - min(x1, min(y3, y2)));
	    }
	    cout << ans << endl;
  	}
	return 0;
}