#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
int a[100001];

struct Node
{
	int val, lazy_a, lazy_d;
	Node(){}
}Seg[400001];	

void diffuse(int node, int l, int r)
{
	Seg[node].val += (Seg[node].lazy_a * (r - l + 1) + Seg[node].lazy_d * (r - l) * (r - l + 1) / 2);
	if (l != r)
	{
		Seg[node * 2].lazy_a += Seg[node].lazy_a;
		Seg[node * 2].lazy_d += Seg[node].lazy_d;
		int mi = (l + r)/2;
		int nxt_a = Seg[node].lazy_a + (mi + 1 - l) * Seg[node].lazy_d;
		Seg[node * 2 + 1].lazy_a += nxt_a;
		Seg[node * 2 + 1].lazy_d += Seg[node].lazy_d;
	}
	Seg[node].lazy_a = Seg[node].lazy_d = 0;
}

void upd(int node, int l, int r, int ll, int rr, int val, int d)
{
	diffuse(node, l, r);
	if (ll > rr)
		return;
	if (r < ll || rr < l)
		return;
	if (ll <= l && r <= rr)
	{
		Seg[node].lazy_a += val + (l - ll) * d;
		Seg[node].lazy_d += d;
		diffuse(node, l, r);
		return;
	}
	int mi = (l + r)/2;
	upd(node * 2, l, mi, ll, rr, val, d);
	upd(node * 2 + 1, mi + 1, r, ll, rr, val, d);
	//Seg[node].val = Seg[node * 2].val + Seg[node * 2 + 1].val; // Not necessary
}

// Not needed

/*
int query(int node, int l, int r, int ll, int rr)
{
	diffuse(node, l, r);
	if (ll > rr)
		return 0;
	if (r < ll || rr < l)
		return 0;
	if (ll <= l && r <= rr)
		return Seg[node].val;
	int mi = (l + r)/2;
	int a = query(node * 2, l, mi, ll, rr);
	int b = query(node * 2 + 1, mi + 1, r, ll, rr);
	return a + b;	
}
*/

int get_ans(int node, int l, int r)
{
	diffuse(node, l, r);
	if (l == r)
		return Seg[node].val;
	int mi = (l + r) /2;
	return min(get_ans(node * 2, l, mi), get_ans(node * 2 + 1, mi + 1, r));
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 2; i <= n; i++)
		if (a[i - 1] < a[i])
		{
			// .....S.....T.....                           
			upd(1, 1, m, 1, a[i - 1], a[i] - a[i - 1], 0); // from 1 to S
			upd(1, 1, m, a[i] + 1, m, a[i] - a[i - 1], 0); // from T + 1 to m

			// from S + 1 to T
			upd(1, 1, m, a[i - 1] + 1, a[i], 1 + a[i], 0);
			upd(1, 1, m, a[i - 1] + 1, a[i], -(a[i - 1] + 1), -1);
		}
		else
		{
			// ....T.....S.....
			upd(1, 1, m, a[i] + 1, a[i - 1], m - a[i - 1] + 1 + a[i] - 1, 0); // from T + 1 to S

			// from S + 1 to m
			upd(1, 1, m, a[i - 1] + 1, m, (1 + a[i] - 1) + 1 + m, 0);
			upd(1, 1, m, a[i - 1] + 1, m, -(a[i - 1] + 1), -1);

			// from 1 to T
			upd(1, 1, m, 1, a[i], 1 + a[i], 0);
			upd(1, 1, m, 1, a[i], -1, -1);
		}
	cout << get_ans(1, 1, m);
}