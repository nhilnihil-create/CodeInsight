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
#define die exit(0)
using namespace __gnu_pbds;  
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update> oset; 
gp_hash_table<int, int> table;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

int n;
int arr[N];

void solve()
{
    int m;
    cin>>n>>m;
    forn(i,1,n)
    {
        cin>>arr[i];
    }
    int a = -1,b;
    forn(i,2,n)
    {
        if(arr[i] + arr[i-1]>=m)
        {
            a = i-1 , b = i;
            break;
        }
    }
    if(a==-1)
    {
        cout<<"Impossible";exit(0);
    }

    cout<<"Possible\n";
    forn(i,1,a-1)
    {
        cout<<i<<"\n";
    }
    rfor(i,n-1,b)
    {
        cout<<i<<"\n";
    }
    cout<<a;


    
}


signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t = 1;
    //cin>>t;
    forn(i,1,t)
    {
        solve();
        nl;
    }



    return 0;

}

//       g++ -g c.cpp ; timeout 2s ./a.out