#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
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

int n;
int a[100005];
set <int> S;

signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i % 2 == 1)
		{
			S.insert(a[i]);
		}
	}	
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i = i + 2)
	{
		if(S.count(a[i]) == true)
		{
			S.erase(a[i]);
		}
	}
	cout << int(S.size());
}