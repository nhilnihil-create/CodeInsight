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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

unordered_map<ll, bool> ma;
unordered_map<ll,bool> visited;
int dx[3] = {-1,0,1};
int dy[3] = {-1,0,1};
int h, w;
const ll MOD = 1e9 + 7;

ll hsh(ii x)
{
	ll r = MOD*ll(x.fi)+ll(x.se);
	return r;
}

bool isvalid(ii x)
{
	if(x.fi >= 2 && x.fi <= h - 1 && x.se >= 2 && x.se <= w - 1) return true;
	return false;
}

ll ans[10];

int test(ii x)
{
	int cnt = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(ma[hsh(ii(dx[i]+x.fi, dy[j]+x.se))]) cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>h>>w>>n;
	vector<ii> color;
	for(int i = 0; i < n; i++)
	{
		int u, v; cin >> u >> v;
		ma[hsh(ii(u,v))] = true; color.pb(ii(u,v));
	}
	
	ans[0] = ll(h-2)*ll(w-2);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				ii tmp = ii(color[i].fi+dx[j], color[i].se+dy[k]);
				ll h = hsh(tmp);
				//cout << "TMP : " << tmp.fi << ' ' << tmp.se << ' ' << test(tmp) << ' ' << isvalid(tmp) << ' ' << visited[tmp] << '\n';
				if(isvalid(tmp) && !visited[h])
				{
					int q = test(tmp);
					ans[q]++;
					visited[h] = true;
				}
			}
		}
	}
	for(int i = 1; i <= 9; i++)
	{
		ans[0] -= ans[i];
	}
	for(int i = 0; i <= 9; i++)
	{
		cout << ans[i] << '\n';
	}
}
