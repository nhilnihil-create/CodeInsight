#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll n, l, t, x, w, ans[100010];
vector<ll> con;
vector<P> clo, rev;

int main()
{
	cin >> n >> l >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> w;
		if (w == 1)
		{
			con.push_back((x + t) % l);
			clo.push_back(P(i, x));
		}
		else
		{
			con.push_back((x + l - (t % l)) % l);
			rev.push_back(P(i, x));
		}
	}
	sort(con.begin(), con.end());
	if (clo.size() == 0)
	{
		for (int i = 0; i < rev.size(); i++)
		{
			ans[rev[i].first] = (rev[i].second + l - (t % l)) % l;
		}
	}
	else if (rev.size() == 0)
	{
		for (int i = 0; i < clo.size(); i++)
		{
			ans[clo[i].first] = (clo[i].second + t) % l;
		}
	}
	else
	{
		ll num = 0;
		for (int i = 0; i < rev.size(); i++)
		{
			ll len = (rev[i].second + l - clo[0].second) % l;
			num += t * 2 / l;
			if (t * 2 % l >= len)
			{
				num++;
			}
		}
		ll u = (clo[0].second + t) % l, s;
		ll ant = (num + clo[0].first) % n;
		if (ant == 0) ant = n;
		for (int i = con.size() - 1; i >= 0; i--)
		{
			if (u == con[i])
			{
				s = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (ant < i)
			{
				ans[i] = con[((i - ant) + s) % n];
			}
			else if (ant == i)
			{
				ans[i] = con[s];
			}
			else
			{
				ans[i] = con[(s + n - (ant - i)) % n];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << endl;
	}
	cin >> n;
}