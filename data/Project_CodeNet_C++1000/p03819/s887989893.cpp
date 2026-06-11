#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 9;

int n, m, ans;
vector<int> a[maxn];
int tree[maxn << 2], lazy[maxn << 2];

void PushUp(int p)
{
	tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void PushDown(int p, int ln, int rn)
{
	lazy[p << 1] += lazy[p];
	lazy[p << 1 | 1] += lazy[p];
	tree[p << 1] += lazy[p] * ln;
	tree[p << 1 | 1] += lazy[p] * rn;
	lazy[p] = 0;
} 
void Modify(int p, int l, int r, int ql, int qr, int val)
{
	if (l >= ql && r <= qr)
	{
		tree[p] += val * (r - l + 1);
		lazy[p] += val;
		return;
	}
	int mid = (l + r) >> 1;
	PushDown(p, mid - l + 1, r - mid);
	if (ql <= mid) Modify(p << 1, l, mid, ql, qr, val);
	if (qr > mid) Modify(p << 1 | 1, mid + 1, r, ql, qr, val);
	PushUp(p);
}
int Query(int p, int l, int r, int ql, int qr)
{
	if (l >= ql && r <= qr)
	{
		return tree[p];
	}
	int mid = (l + r) >> 1;
	PushDown(p, mid - l + 1, r - mid);
	int ans = 0;
	if (ql <= mid) ans += Query(p << 1, l, mid, ql, qr);
	if (qr > mid) ans += Query(p << 1 | 1, mid + 1, r, ql ,qr);
	return ans;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int l, r;
		cin>>l>>r;
		a[r - l + 1].push_back(l);
	}
	for (int i=1;i<=m;i++)
	{
		ans = n;
		for (int j=i;j<=m;j+=i)
		{
			ans += Query(1, 1, m, j, j);
		}
		for (int j=0;j<a[i].size();j++)
		{
			Modify(1, 1, m, a[i][j], a[i][j] + i - 1, 1);
			n--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
