#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
using namespace         std;
#define                 int long long
#define                 double long double
#define                 pb push_back
#define                 mp make_pair
#define st(arr,a)       memset(arr,a,sizeof arr)
#define                 nl cout<<endl
#define                 endl '\n'              
#define bitcount(x)     __builtin_popcountll(x)
const int MOD = 1000000007ll;
#define forn(i,a,b)     for(int i=a;i<=b;i++)
#define rfor(i,a,b)     for(int i=a;i>=b;i--)
#define all(x)          x.begin() , x.end()
#define pi pair<int,int>
#define X first
#define Y second
#define N 1014159
#define  vi vector<int>
#define  v  vector
using namespace __gnu_pbds;  
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update> oset; 
gp_hash_table<int, int> table;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

int arr[N];

multiset<int>one,two;
int pos = 0;
int A[N],B[N];
void solve()
{
	int n,k;
	cin>>n>>k;
    forn(i,1,n)
	{
		cin>>arr[i];
		if(arr[i]<0)
		{
			A[i] =arr[i] + A[i-1];
			B[i] = B[i-1];
		}
		else
		{
			A[i] = A[i-1];
			B[i] = B[i-1] + arr[i];
			pos+=arr[i];
		}
		
		
	}
	//forn(i,1,n)cout<<A[i]<<" ";nl;
	int ans = 0;
	forn(i,k,n)
	{
		ans = max(ans,pos + A[i] - A[i-k]);
		ans = max(ans,pos - B[i] + B[i-k]);
	}
	cout<<ans;

}


signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }nl;



    return 0;

}

//       g++ -g c.cpp ; ./a.out