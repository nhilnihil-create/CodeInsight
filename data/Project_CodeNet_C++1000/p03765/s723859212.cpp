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

ll pre[N];
ll pr2[N];
int main()
{
	cin >>  s >>t;
	ll q;
	cin >> q;
	ll n = s.size();
	for(int i =1;i<=n;i++)
	{
		if(s[i-1] == 'A')
		{
			pre[i] = pre[i-1] + 1;
		}
		else pre[i] = pre[i-1] + 2;
		
		if(t[i-1] == 'A')
		{
			pr2[i] = pr2[i-1] + 1;
		}
		else pr2[i] = pr2[i-1] + 2;
	}

	while(q--)
	{
		ll l,r,x,y;
		cin>> l >>r >>x >>y;
		
		ll sum1 = pre[r] - pre[l-1];
		ll sum2 = pr2[y] - pr2[x-1];
		sum1 %= 3;
		sum2 %= 3;
		//cout << sum2 << " " << sum1 << endl;
		if(sum2==sum1) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}