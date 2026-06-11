#include <bits/stdc++.h> 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ld double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define sz(x) ((long long)x.size())
#define all(x) (x).begin(), (x).end()
const int MOD =1e9+7;
#define oset(x) tree<x, null_type, less<x>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1LL;}return res%p;}
const int N=2*1e5+2,M=201;

void solve()
{
	int n,x;
	cin>>n>>x;
	n=2*n-1;
	if(x==1||(x==n))
	{
		cout<<"No\n";
	}		
	else{
		set<int> s;
		for(int i=1;i<=n;i++) s.insert(i);
		int ans[n+1]={0};
		if(x!=2)
		{
			// cout<<"*";
			int pos=n/2;
			ans[pos]=x-1;
			pos++;
			ans[pos]=x;
			pos++;
			ans[pos]=x+1;
			pos++;
			ans[pos]=x-2;
			s.erase(x-1);
			s.erase(x);
			s.erase(x+1);
			s.erase(x-2);
			for(int i=1;i<=n;i++)
			{
				if(ans[i]==0)
				{
					ans[i]=*s.begin();
					s.erase(ans[i]);
				}
			}
		}
		else{
			int pos=n/2;
			ans[pos]=x+1;
			pos++;
			ans[pos]=x;
			pos++;
			ans[pos]=x-1;
			pos++;
			ans[pos]=x+2;
			s.erase(x+1);
			s.erase(x);
			s.erase(x-1);
			s.erase(x+2);
			for(int i=1;i<=n;i++)
			{
				if(ans[i]==0)
				{
					ans[i]=*s.begin();
					s.erase(ans[i]);
				}
			}
		}
		cout<<"Yes\n";
		for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
	}
}
// 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t=1;
	// cin>>t;
	while(t--)
		solve();
} 