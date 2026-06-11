#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
typedef long long   ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define fi first
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef pair<ll, ii>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9;
const double PI = acos(-1);
#define offset 
const ll MOD= 1e9+7;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 103455

int v[tam];
int  main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,L;
    cin>>n>>L;
    forr(i,0,n)
    {
        cin>>v[i];
    }
    vector<int> sol;
    forr(i,0,n-1)
    {
        if (v[i]+v[i+1]>=L)
        {
            forr(j,0,i)
            sol.pb(j+1);
            for(int j=n-1;j>=i+2;j--)
            sol.pb(j);
            sol.pb(i+1);
            cout<<"Possible\n";
            for(auto num:sol)
                cout<<num<<endl;
            return 0;
        }
    }
    cout<<"Impossible\n";
}
// PLUS ULTRA!!