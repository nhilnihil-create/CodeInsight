#include <bits/stdc++.h>
#define adj_list vector<vi>
#define endl "\n"
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pair<int, int> >
#define pl pair<ll, ll>
#define pll pair<ll, pair<ll, ll> >
#define vi vector<int>
#define vl vector<ll>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int lsone(int n)
{
	return (n&-n);
}

ll pow1(ll a, ll b)
{
	if (b == 0)
		return 1ll;
	else if (b == 1)
		return a;
	else
	{
		ll x = pow1(a, b/2);
		x *= x;
		x %= mod;
		if (b%2)
		{
			x *= a;
			x %= mod;
		}
		return x;
	}
}

int h, w, a, b;
ll fact[220000], factinv[220000];
int main()
{
	fastio;		

	fact[0] = 1;
	factinv[0] = 1;
	for (int i = 1; i <= 200000; i++)
	{
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;

		factinv[i] = pow1(fact[i], mod-2);
	}

	cin>>h>>w>>a>>b;

	if (0)
	{
		ll ans = (fact[h+w-2]*factinv[h-1])%mod;
		ans *= (factinv[w-1]);
		ans %= mod;

		ll rem = (fact[h+b-2]*factinv[h-1])%mod;
		rem *= (factinv[b-1]);
		rem %= mod;

		ll rem2 = (fact[(h+w-2)-(h+b-2)]*factinv[w-b])%mod;

		rem = rem*rem2;
		rem %= mod;

		ans = (ans + mod - rem)%mod;

		cout<<ans<<"\n";
	}
	else
	{
		ll ans = (fact[h+w-2]*factinv[h-1])%mod;
		ans *= (factinv[w-1]);
		ans %= mod;

		ll rem = 0;

		for (int i = 0; i <= b-1; i++)
		{	
			if (i == b-1)
			{
				ll curr = (fact[h-a+i]*factinv[h-a])%mod;
				curr *= (factinv[i]);
				curr %= mod;
				ll curr2 = (fact[(h+w-2)-(h-a+i)]*factinv[(h-1)-(h-a)])%mod;
				curr2 *= (factinv[(w-1)-i]);
				curr2 %= mod;

				curr = (curr*curr2)%mod;

				rem += curr;
				rem %= mod;
			}
			else
			{
				ll curr = (fact[h-a+i]*factinv[h-a])%mod;
				curr *= (factinv[i]);
				curr %= mod;
				ll curr2 = (fact[(h+w-2) - (h-a+1+i)]*factinv[(h-1)-(h-a+1)])%mod;
				curr2 *= (factinv[(w-1)-i]);
				curr2 %= mod;

				curr = (curr*curr2)%mod;

				rem += curr;
				rem %= mod;
			}
		}

		//cout<<ans<<" "<<rem<<"\n";

		ans = (ans + mod - rem)%mod;

		cout<<ans<<"\n";
	}

	return 0;
}
