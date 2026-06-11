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
 
const int MOD = 1e9 + 7;
 
ll x[100001];
ll y[100001];
 
ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}
 
ll add(ll a, ll b)
{
	return (a+b)%MOD;
}
 
ll a[100001];
ll b[100001];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<m;i++) cin>>y[i];
	for(int i=0;i+1<n;i++) a[i]=x[i+1]-x[i];
	for(int i=0;i+1<m;i++) b[i]=y[i+1]-y[i];
	n--; m--;
	ll ans1 = 0;
	ll ans2 = 0;
	for(int i = 0; i < n; i++)
	{
		ans1 = add(ans1,mult(i+1,mult(n-i,a[i])));
	}
	for(int i = 0; i < m; i++)
	{
		ans2 = add(ans2,mult(i+1,mult(m-i,b[i])));
	}
	cout<<mult(ans1,ans2)<<'\n';
}