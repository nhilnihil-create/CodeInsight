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
const ll MOD= 998244353;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 300000

int  main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int valor;
    set<int> primer,segund;
    vector<int> v;
    forr(i,0,n)
    {
        cin>>valor;
        if (i%2==0)
            primer.insert(valor);
        else
            segund.insert(valor);
        v.pb(valor);
    }
    sort(all(v));
    int c=0;
    forr(i,0,n)
    {
        if (i%2==0)
        {
            if (primer.find(v[i])==primer.end())c++;
        }
    }
    cout<<c<<endl;      
    
}
// PLUS ULTRA!!