#include<bits/stdc++.h>
using namespace std;
#define int long long int
/*typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;*/


#define mod 1000000007
#define INF 1e9+100
#define ff first
#define ss second
#define cy cout<<"yes"<<endl;
#define cn cout<<"no"<<endl;
#define urs(r...)          typename decay<decltype(r)>::type
#define fi(i,n)                for(urs(n) i=0;i<n;i++)
#define rep(i,n)               for(urs(n) i=1;i<=n;i++)
#define pb push_back
#define gap ' '
#define endl '\n'
#define mex 600008
#define what_is(x)              cerr << #x << " is " << x << endl;

#define bintotalones(x)         __builtin_popcountll(x)
#define binleadingzeroes(x)     __builtin_clzll(x)
#define bintrailingzeroes(x)    __builtin_ctzll(x)
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;*/
//N%P=(N&(P-1)) where P is a power of 2
main()
{
	int i,j,n,m;
	int x,k,y;
	cin>>n>>k>>x>>y;
	int fir=min(n,k)*x;
	int sum=fir;
	if(n-k>0) sum+=(n-k)*y;
	cout<<sum<<endl;
}
