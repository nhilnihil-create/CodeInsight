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
 
int x[501];
int a[250001];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	deque<ii> require;
	deque<ii> require2;
	vector<ii> v;
	for(int i = 1; i <= n; i++)
	{
		cin>>x[i];
		x[i]--;
		if(a[x[i]]!=0)
		{
			cout<<"No\n"; return 0;
		}
		a[x[i]]=i;
		v.pb(mp(x[i],i));
	}
	sort(v.begin(),v.end());
	for(int i = 0; i < n; i++)
	{
		if(v[i].se>1) require.pb(mp(v[i].se-1,v[i].se));
	}
	int ptr = 0;
	for(int i = 0; i < n; i++)
	{
		while(ptr<v[i].fi)
		{
			if(require.empty()&&require2.empty())
			{
				cout<<"No\n"; return 0;
			}
			if(!require.empty())
			{
				a[ptr] = require.front().se;
				require.front().fi--;
				if(require.front().fi==0) require.pop_front();
			}
			else
			{
				a[ptr] = require2.front().se;
				require2.front().fi--;
				if(require2.front().fi==0) require2.pop_front();
			}
			ptr++;
		}
		ptr++;
		if(n-v[i].se>0) require2.pb(mp(n-v[i].se,v[i].se));
	}
	if(!require.empty())
	{
		cout<<"No\n"; return 0;
	}
	while(ptr<n*n)
	{
		if(require2.empty())
		{
			cout<<"No\n"; return 0;
		}
		a[ptr] = require2.front().se;
		require2.front().fi--;
		if(require2.front().fi==0) require2.pop_front();
		ptr++;
	}
	int cnt[n+1];
	memset(cnt,0,sizeof(cnt));
	for(int i = 0; i < n*n; i++)
	{
		cnt[a[i]]++;
		if(cnt[a[i]]>n)
		{
			cout<<"No\n"; return 0;
		}
		if(cnt[a[i]]==a[i]&&i!=x[a[i]])
		{
			cout<<"No\n"; return 0;
		}
	}		
	
	cout<<"Yes\n";
	for(int i = 0; i <n*n;i++)
	{
		cout<<a[i];
		if(i<n*n-1) cout<<' ';
	}
	cout<<'\n';
}
