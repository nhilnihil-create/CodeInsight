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
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++) a[i]+=a[i-1];
	s.insert({0-(-1)*k,-1});
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x=a[i]-k*i;
		int get=s.order_of_key({x+1,-1e12});
		ans+=get;
		// cout<<get<<" ";
		s.insert({x,i});
	}
	cout<<ans;
}
// i, j
// (10-0)/(1)>=26
// (sum[j]-sum[i])/(j-i)>=k
// sum[j]-sum[i]>=k*j-k*i
// sum[j]-k*j>=sum[i]-k*i
// 