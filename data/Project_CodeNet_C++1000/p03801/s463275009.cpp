#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 1e5+5;
int arr[maxn];
ll ans[maxn];
int n;

struct node
{
	ll sum;
	int mx;
};

node st[4*maxn];
int lz[4*maxn];

void pushdown(int p, int L, int R)
{
	if(lz[p] == -1) return;
	st[p].sum = 1LL*(R-L+1)*lz[p];
	st[p].mx = lz[p];
	if(L != R)
	{
		lz[2*p] = lz[2*p+1] = lz[p];
	}
	lz[p] = -1;
}

node pull(node &x, node &y)
{
	node res;
	res.sum = x.sum + y.sum;
	res.mx = max(x.mx, y.mx);
	return res;
}

void update(int i, int j, int dx, int p = 1, int L = 1, int R = n)
{
	pushdown(p, L, R);
	if(i> R || j< L) return;
	if(i<= L && R<= j)
	{
		lz[p] = dx;
		pushdown(p, L, R);
		return;
	}
	int M = (L+R)/2;
	update(i, j, dx, 2*p, L, M);
	update(i, j, dx, 2*p+1, M+1, R);
	st[p] = pull(st[2*p], st[2*p+1]);
}

node ask(int i, int j, int p = 1, int L = 1, int R = n)
{
	if(i> R || j< L)
	{
		node res;
		res.sum = 0;
		res.mx = -1e9;
		return res;
	}
	pushdown(p, L, R);
	if(i<= L && R<= j) return st[p];
	int M = (L+R)/2;
	node x = ask(i, j, 2*p, L, M);
	node y = ask(i, j, 2*p+1, M+1, R);
	node res = pull(x, y);
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i<= n; i++) scanf("%d", arr+i);
	vector< ii > st;
	for(int i = 1; i<= n; i++)
	{
		if(st.empty() || st.back().fi< arr[i]) st.push_back(ii(arr[i], i));
	}
	sort(arr+1, arr+n+1);
	for(int i = 1; i<= n; i++) update(i, i, arr[i]);
	for(int i = (int) st.size()-1; i>= 0; i--)
	{
		int tar = i?st[i-1].fi:0;
		int lo = 1, hi = n;
		while(lo< hi)
		{
			int mid = (lo+hi)/2;
			node here = ask(1, mid);
			if(here.mx>= tar) hi = mid;
			else lo = mid+1;
		}
		node res = ask(lo, n);
		update(lo, n, tar);
		ans[st[i].se] = res.sum - 1LL*(n-lo+1)*tar;
	}
	for(int i = 1; i<= n; i++) printf("%lld\n", ans[i]);
}