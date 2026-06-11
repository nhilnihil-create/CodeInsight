#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>

using namespace std;

const ll N = 4e5+100;
const ll MOD = 1e9+7;
string s,t;
ll tree[N];

void build(ll node,ll l,ll r)
{
	if(l==r)
	{
		tree[node] = (s[l-1] == t[r-1]);
	}
	else
	{
		ll mid = (l + r) >> 1LL;
		build(node*2,l,mid);
		build(2*node+1,mid+1,r);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
}

ll query(ll node,ll st,ll en,ll l,ll r)
{
	if(r < st || l> en) return 0;
	if(st >= l && en <= r) return tree[node];
	ll mid = (st + en)/2;
	ll p1 = query(node*2,st,mid,l,r);
	ll p2 = query(node*2+1,mid+1,en,l,r);
	return p1 + p2;
}
ll dp[1000005];
ll pre[1000005];
int main()
{
	ll n;
	cin >> n;
	if(n==1) return cout<<n << endl,0;
	if(n==2) return cout <<  (n *n) %MOD << endl,0;
	dp[0] = 1;
	dp[1] = 1;
	ll ans = (n-1 + (n-1) * (n-1) * 2) %MOD;
	for(ll k  =2,i = 1;k<n;k++)
	{
		dp[k] = (i % MOD);
		ll xx;
		if(k==n-1) xx = 1;
		else xx = n-1;
		ans = (ans + dp[k] * (n-1) % MOD * (xx) % MOD ) %MOD;	
		ans = (ans + (n-1) * dp[k-1] %MOD)	%MOD;
		i = (i + dp[k] + dp[k-2] - dp[k-1] + MOD) %MOD;
	}
	ans++;
	if(ans < MOD) ans += MOD;ans%=MOD;
	cout << ans << endl;
	
	
	return 0;
}