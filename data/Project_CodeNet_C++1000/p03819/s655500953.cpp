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

struct PBDS
{
	tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> t;
	int timer;
	
	PBDS(){timer = 0;}
	void insert(int x)
	{
		t.insert(mp(x, timer));
		timer++;
	}
	
	int lower(int x)
	{
		return t.order_of_key(ii(x, -1));
	}
	
	void del(int x) //make sure x exists
	{
		ii tmp = (*t.find_by_order(lower(x)));
		t.erase(tmp);
	}
	
	int higher(int x)
	{
		int tmp = lower(x+1);
		return (int(t.size()) - tmp);
	}
};

int ans[111111];
int L[111111];
vi d[111111];
vi add[111111];
vi rem[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i = 2; i <= 100000; i++)
	{
		for(int j = i; j <= 100000; j+=i)
		{
			d[j].pb(i);
		}
	}
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		int l, r; cin>>l>>r;
		L[1]++;
		L[r-l+2]--;
		add[l].pb(r-l+1); //at least r-l+2 to count
		rem[r+1].pb(r-l+1);
	}
	PBDS t;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < add[i].size(); j++) t.insert(add[i][j]);
		for(int j = 0; j < rem[i].size(); j++) t.del(rem[i][j]);
		for(int j = 0; j < d[i].size(); j++)
		{
			int D = d[i][j];
			int cnt = t.lower(D);
			ans[D]+=cnt;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		L[i]+=L[i-1];
		ans[i]+=L[i];
	}
	for(int i = 0; i < m; i++)
	{
		cout<<ans[i+1]<<'\n';
	}
}
