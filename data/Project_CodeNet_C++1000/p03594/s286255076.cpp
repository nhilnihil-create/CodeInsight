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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

char col[4] = {'R','Y','G','B'};
char a[511][511];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			a[i][j] = col[((i+j)%(2*k) >= k)*2 + ((i-j+(2*k)*10000)%(2*k) >= k)%2];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<'\n';
	}
}
