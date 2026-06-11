#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
using namespace         std;
#define                 int long long
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
int n,l;
int nex[N][20];

void solve()
{
    cin>>n;
    forn(i,1,n)
    {
        cin>>arr[i];
    }
    
    int last = n;
    cin>>l;
    rfor(i,n-1,0)
    {
        while(arr[last] - arr[i] > l)
        {
            last--;
        }
        nex[i][0] = last;
    }
    nex[n][0] = n;
    
    ///forn(i,1,n)cout<<nex[i][0]<<" ";nl;
    
    
    forn(i,1,17)forn(j,0,n)nex[j][i] = nex[nex[j][i-1]][i-1];
    
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        int now = a;
        int ans = 1;
        rfor(i,17,0)
        {
            if(nex[now][i]<b)
            {
                now = nex[now][i];
                ans+=1LL<<i;
            }
        }
        cout<<ans<<"\n";
        
    }
    
    
    
}


signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }



    return 0;

}

//       g++ -g c.cpp ; ./a.exe