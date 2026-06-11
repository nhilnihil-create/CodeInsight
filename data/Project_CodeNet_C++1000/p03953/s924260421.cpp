#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

void p(ld ans)
{
	cout << fixed << setprecision(12) << ans << '\n';
}

ll x[100001];
int r[100001];
ll d[100001];
vi perm;
const int LG = 61;
int st[LG][100001];

int getval(int x, ll k)
{
	int pos = x;
	for(int i = 0; i < LG; i++)
	{
		if(k&(1LL<<i))
		{
			pos = st[i][pos];
		}	
	}
	return pos;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i];
	ll m, k; cin >> m >> k;
	for(int i = 0; i < m; i++) 
	{
		cin >> r[i];
		r[i]--;
	}
	d[0] = 0;
	for(int i = 1; i < n; i++)
	{
		d[i] = x[i] - x[i-1];
	}
	for(int i = 0; i < n; i++) perm.pb(i);
	for(int i = 0; i < m; i++)
	{
		swap(perm[r[i]], perm[r[i]+1]); //check
	}
	vi perm2(n);
	for(int i = 0; i < n; i++)
	{
		perm2[perm[i]] = i;
	}
	for(int i = 0; i < n; i++)
	{
		st[0][i] = perm2[i];
	}
	for(int i = 1; i < LG; i++)
	{
		for(int j = 0; j < n; j++)
		{
			st[i][j] = st[i-1][st[i-1][j]];
		}
	}
	for(int i = 0; i < n; i++)
	{
		int pos = getval(i, k);
		perm2[pos] = i;
	}
	ld sum = ld(x[0]);
	for(int i = 0; i < n; i++)
	{
		sum += ld(d[perm2[i]]);
		p(ld(sum));
	}
}
