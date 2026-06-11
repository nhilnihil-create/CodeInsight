#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9;
const double PI = acos(-1);
#define offset 
const ll MOD= 1e9+7;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 223455
ll n;
ll arr[tam],v[tam];
ll A,B;
int f(ll num)
{
    forr(i,0,n){
        arr[i]=v[i]-num*B;
        //cout<<arr[i]<<" ";
    }

    ll cant=0;
    forr(i,0,n)
    {
        if (arr[i]<=0)continue;
        cant+=((arr[i])/(A-B))+((arr[i]%(A-B))!=0);
    }
    //cout<<cant<<endl;
    return cant<=num;
}
int  main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    
    cin>>n;
    cin>>A>>B;
    forr(i,0,n)
        cin>>v[i];
    sort(v,v+n);
    //cout<<f(800000000-1)<<endl;
    //return 0;
    ll iz=0,der=1e9,mid;
    while(iz+1<der)
    {
        mid=(iz+der)/2;
        if (f(mid)==0)
            iz=mid;
        else
            der=mid;
    }
    cout<<der<<endl;
}
// PLUS ULTRA!ac