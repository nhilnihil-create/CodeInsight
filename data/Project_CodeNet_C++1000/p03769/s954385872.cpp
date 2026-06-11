#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(), v.end()
#define fori(i, j, k) for (int i = (j); i < (int)(k); i++)
#define forb(i, j, k) for (int i = (j); i >= (int)k; i--)
#define lchild(ind) 2 * ind + 1
#define rchild(ind) 2 * ind + 2
#define bug(val) cout << "# " << val << endl;
#define bugs(val) cout << '_' << val;
#define bugl(val) cout << "## " << val << endl;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<int, pll> pip;
typedef pair<ll, pll> plp;
typedef pair<pll, int> ppi;
typedef pair<pll, ll> ppl;
typedef pair<pll, pll> ppp;
typedef vector<int> vi;
typedef vector<ll> vll;

const int maxn = 1e5 + 1;
const ll inf = 2e18, mod = 1e9 + 7;

int ind = 1;

deque<int> solve(ll n)
{
	deque<int> res;
	if (!n)
		return res;
	if (n == 1)
	{
		res.pb(ind), res.pb(ind);
		ind++;
		return res;
	}
	if (n == 2)
	{
		res.pf(ind), res.pb(ind);
		ind++;
		res.pf(ind), res.pb(ind);
		ind++;
		return res;
	}
	if (n & 1)
	{
		deque<int> tmp = solve((n - 1) / 2);
		fori (i, 0, tmp.size())
		{
			if (i == (int)tmp.size() / 2)
				res.pb(ind);
			res.pb(tmp[i]);
		}
		res.pb(ind++);
		return res;
	}
	else
	{
		deque<int> tmp = solve((n - 2) / 2);
		fori (i, 0, tmp.size())
		{
			if (i == (int)tmp.size() / 2)
				res.pb(ind);
			res.pb(tmp[i]);
		}
		res.pb(ind++);
		res.pf(ind), res.pb(ind), ind++;
		return res;
	}
}

int get(deque<int> a)
{
	int n = a.size(), res = 0;
	vi A, B;
	fori (mask, 1, (1 << n))
	{
		int cnt = __builtin_popcount(mask), now = 0;
		if (cnt & 1)
			continue;
		A.clear(), B.clear();
		fori (i, 0, n)
			if ((mask >> i) & 1)
			{
				cerr << a[i] << ' ';
				if (now < cnt / 2)
					A.pb(a[i]);
				else
					B.pb(a[i]);
				now++;
			}
		cerr << ':' << (A == B) << endl;
		res += (A == B);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	deque<int> ans = solve(n);
	cout << ans.size() << endl;
	for (int i : ans)
		cout << i << ' ';
	cout << endl;
}





















