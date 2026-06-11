#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
using cd = complex <double>;

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

int n, l;
int a[100005], id = 0;

signed main()
{
	Fastio();
	cin >> n >> l;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n - 1; i++)
	{
		if(a[i] + a[i + 1] >= l)
		{
			id = i;
			break;
		}
	}
	if(id == 0)
	{
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for(int i = 1; i < id; i++)
	{
		cout << i << '\n';
	}
	for(int i = n - 1; i > id; i--)
	{
		cout << i << '\n';
	}
	cout << id;
}