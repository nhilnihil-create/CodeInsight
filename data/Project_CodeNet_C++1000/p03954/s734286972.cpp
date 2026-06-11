//Ilm kave oi, you know ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)3e5 + 3;
const int infint = (int)1e9 + 3;
const ll inf = (ll)1e12;
int n, a[MAXN], b[MAXN];
bool check(int mid)
{
	for (int i = 0; i < n; i++)
		b[i] = (a[i] >= mid);
	
	int ptr = n / 2;
	int l = -1, r = n;
	for (int i = ptr; i < n - 1; i++)
		if(b[i] == b[i + 1])
		{
			r = i;
			break;
		}
	for (int i = ptr; i >= 1; i--)
		if(b[i] == b[i - 1])
		{
			l = i;
			break;
		}
	if(l == -1 && r == n)
		return b[0];
	if(ptr - l < r - ptr)
		return b[l];
	else
		return b[r];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	n = n * 2 - 1;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int L = 1, R = n + 1;
	while(R - L > 1)
	{
		int mid = (L + R) >> 1;
		if(check(mid))
			L = mid;
		else
			R = mid;
	}
	cout << L;
}
