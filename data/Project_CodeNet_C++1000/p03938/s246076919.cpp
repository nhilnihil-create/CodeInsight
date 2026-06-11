#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
const ll MAXN = 1e6 + 10;
const ll N = 4000 + 10;
const ll MN = 200 + 10;
const ll mod = 1e9 + 7;
 
ll a[MAXN];
ll b[MAXN];
ll c[MAXN];
 
int main()	
{
	faster();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		c[x - 1] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = 20000 * (i + 1) * 1LL;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b[i] = 20000 * (n - i - 1) + c[i] * 1LL;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
}