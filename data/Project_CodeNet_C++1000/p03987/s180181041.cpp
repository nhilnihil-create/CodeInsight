#include <bits/stdc++.h> 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
#define ld double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD =1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1LL;}return res%p;}
const int N=2*1e5+2,M=20;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set s;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	// freopen("out10.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	vector<pii> v;
	for(int i=0;i<n;i++)
	{
		v.pb({a[i],i});
	}
	sort(all(v));
	set<int> s;
	s.insert(-1);
	s.insert(n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x=v[i].se;
		auto lol=s.upper_bound(x);
		int r=*lol;
		lol--;
		int l=*lol;
		ans+=(r-x)*(x-l)*v[i].fi;
		s.insert(v[i].se);
	}
	cout<<ans;
}