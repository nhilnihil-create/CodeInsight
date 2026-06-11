#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define mod 998244353
#define mod2 1000000006
#define inf 1000000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<lli>
#define vii vector<int>
#define is indexed_set
#define eps 0.000001
#define endl '\n'
#define mo 998244353
#define pi 3.141592653589793
using namespace std ;
 
const lli dx4[] = {-1, 0, 1, 0};
const lli dy4[] = {0, 1, 0, -1};
const lli dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const lli dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
 
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
 
#define N 1000005

void solve()
{
	lli n;
	cin>>n;

	lli a[2*n];
	loopl(i,0,2*n) cin>>a[i];

	sort(a,a+2*n);

	lli cnt=0;
	for(lli i=0;i<2*n;i+=2) cnt+=a[i];

		cout<<cnt<<endl;
}
 
int main()
{
/////////////////////////////////////
    
    fastio;
 
/////////////////////////////////////  
 	
	lli t;
	t=1;
 
	while(t--)
		solve();
 
}