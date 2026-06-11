//Be Name Khoda
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma optimize O3
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long int LL;
typedef LL ll;
typedef long double ld;
typedef string str;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef stringstream strs;
 
#define X first
#define Y second
#define PB push_back
#define For(i,a,b) for (int i=a;i<b;i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define SZ(a) ((ll)a.size())
#define ER(a) cout << #a << ' ' << a << endl
#define LB(a,n,x) (lower_bound(a,(a)+(n),x)-(a))
#define RET(x) { cout << x; exit(0); } 
#define RETD(x) { cout << fixed << setprecision(15) << x; exit(0); }
const ll M=2e3+5,LG=32,SM=600+5,inf=1e18+5;
ll mod=1e9+7;
 
ll n,m,h,w;
 
int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> h >> w;
	ll f=10000;
	f*=f;
	f=10*f/(h*w);
	ll g=(h*w-1)*f+1;
	ll su=0;
	For(i,1,n+1)
	{
	    For(j,1,m+1)
	    {
	        if (i%h==0 && j%w==0)
	        {
	            su-=g;
	        }
	        else su+=f;
	    }   
	}
	if (su<=0) RET("No");
	cout << "Yes\n";
	For(i,1,n+1)
	{
	    For(j,1,m+1)
	    {
	        if (i%h==0 && j%w==0)
	        {
	            cout << -g << ' ';
	        }
	        else cout << f << " ";
	    }   
	    cout << '\n';
	}
} 