#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
using cd = complex <double>;

typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 998244353;//786433;//998244353;
const double Pi = acos(-1);

 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int a[400005], L[400005];
int Ans[400005][25];
long long res;

int Min(int x, int y)
{
	if(a[x] < a[y])
	{
		return x;
	}
	else
	{
		return y;
	}
}

int M(int l, int r)
{
	int temp = L[r - l + 1];
	int re = (1 << temp);
	re = r + 1 - re;
	return Min(Ans[l][temp], Ans[re][temp]);
}

void DNC(int l, int r)
{
	if(l > r)
	{
		return;
	}
	if(l == r)
	{
		res += a[l];
		return;
	}
	long long temp = M(l, r);
	res += (temp - l + 1) * (r - temp + 1) * a[temp];
	DNC(l, temp - 1);
	DNC(temp + 1, r); 
}

signed main()
{
	cin >> n;
	L[1] = 0;
	for(int i = 2; i <= 400000; i++)
	{
		L[i] = L[i >> 1] + 1;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		Ans[i][0] = i;
	}
	for(int i = 1; i <= 20; i++)
	{
		for(int j = 0; j + (1 << (i - 1)) <= n; j++)
		{
			int temp = 1 << (i - 1);
			Ans[j][i] = Min(Ans[j][i - 1], Ans[j + temp][i - 1]);
		}
	}
	DNC(0, n - 1);
	cout << res;
}