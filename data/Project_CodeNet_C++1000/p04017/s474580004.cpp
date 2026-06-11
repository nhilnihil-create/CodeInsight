#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int n, L, m;
int a[100010];
int block, num;
int b[100010];
int to[100010];
int val[100010];
int nxt[100010];

int find(int x)
{
	int l = x + 1;
	int r = n;
	int ans;
	while(l <= r)
	{
		int mid = (l+r)/2;
		if(a[mid] - a[x] <= L)
		{
			ans = mid ;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return ans;
}

void build(void)
{
	block = sqrt(n);
	num = ceil(1.0*n / block);
	for(int i=1; i<=n; i++)
	{
		b[i] = (i-1) / block + 1;
	}
	for(int i=1; i<n; i++)
	{
		int t = i;
		int sp = 0;
		while(b[i] == b[t])
		{
			t = to[t];
			sp++;
		}
		val[i] = sp;
		nxt[i] = t;
	}
}

int query(int x, int y)
{
	int ans = 0;
	while(b[x] < b[y])
	{
		ans += val[x];
		x = nxt[x];
	}
	while(x < y)
	{
		x = to[x];
		ans++;
	}
	return ans;
}

int main(void)
{
	cin >> n; 
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	cin >> L >> m;
	for(int i=1; i<n; i++)
	{
		to[i] = find(i);
	}
	to[n] = n+1;
	build();
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		if(x > y)
		{
			swap(x, y);
		}
		cout << query(x, y) << endl;
	}
	return 0;
}



















