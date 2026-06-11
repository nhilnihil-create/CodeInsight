#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
//#define int long long
#define ll long long
#define vi vector <int>
#define vii vector <pair<int,int> >
#define vvi vector <vi>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define repD(i,a,b) for (int i=a;i>b;i--)
#define pb push_back
#define pii pair <int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define MOD 1000000007
#define PI 3.14159265359
 
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///*X.find_by_order("index")
///X.order_of_key("key")
 
#define deb(x) {x}
#ifndef local
	#define deb(x) ;
#endif
 
///----------------------------------------------------------------------------------

const int mod = 61559;
int n, k, arr[5005];
unsigned short Forward[5005][5005], backward[5005][5005][2], DP[5005][5005];
bitset <5005> vis[5005];
int fun(int ind, int rem)
{
	if (ind == n && rem == 0) return 1;
	if (ind == n) return 0;
	if (vis[ind][rem]) return DP[ind][rem];
	
	// I go
	vis[ind][rem] = 1;
	int res = 0;
	backward[ind][rem][1] = fun(ind+1, max(0, rem-arr[ind]));
	res = backward[ind][rem][1];
	
	
	// I dont go
	
	backward[ind][rem][0] = fun(ind+1, rem);
	res += backward[ind][rem][0];
	
	if (res >= mod) res -= mod;
	return DP[ind][rem] = res;
}
bool upper = true;
int fun2(int ind, int rem)
{
	if (rem < 0)
	{
		if (! upper) return 0;
		rem = 0;
	}
	if (ind == n && rem == 0) return 1;
	if (ind == n) return 0;
	if (vis[ind][rem]) return DP[ind][rem];
	vis[ind][rem] = 1;
	// I go
	
	int res = fun2(ind+1,rem-arr[ind]);
	
	// I dont go
	
	Forward[ind][rem] = fun2(ind+1, rem);
	res += Forward[ind][rem];
	
	if (res >= mod) res -= mod;
	return DP[ind][rem] = res;
}


void solve()
{
	
	cin >> n >> k;
	rep(i,0,n) cin >> arr[i];
	
	memset(vis, 0, sizeof vis);
	
	
	rep(i,0,k+1)fun(0, i);
	
	reverse(arr, arr+n);
	
	
	memset(vis, 0, sizeof vis);
	
	fun2(0, k);
	upper = false;
	
	memset(vis, 0, sizeof vis);
	rep(i,0,k)fun2(0, i);
	
	reverse(arr, arr+n);
	
	int ans = 0;
	
	rep(i,0,n)
	{
		int num_with_me = 0, num_without_me = 0;
		
		rep(j,0,k+1)
		{
				num_with_me += ( Forward[n-i-1][j] * backward[i][k-j][1]);
				num_without_me += ( Forward[n-i-1][j] * backward[i][k-j][0]);
			
		}
		if (num_without_me == num_with_me) ans++;
	}
	cout << ans << "\n";
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	
 	#ifdef local
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	clock_t qwertyuiop = clock();
	#endif
 
	int t = 1;
	//cin >> t;	
	rep(a,0,t)
	{
		//cout<<"Case #"<<a+1<<": ";
		solve();
		#ifdef local
			cout << "\n";
		#endif

	}
	
	#ifdef local
	{qwertyuiop = clock() - qwertyuiop;double time_taken = ((double)qwertyuiop)/CLOCKS_PER_SEC;cerr<<fixed<<setprecision(5)<<"\n\nTime Taken : "<<time_taken<<" seconds\n";}
	#endif
}
