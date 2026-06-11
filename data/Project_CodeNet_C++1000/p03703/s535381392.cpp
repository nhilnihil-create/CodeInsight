#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef pair<ll, ii>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9;
const double PI = acos(-1);
#define offset 
const ll MOD= 1e9+7;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 223455
ll v[tam];
ll sum[tam];
int  main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,k;
    cin>>n>>k;
    forr(i,1,n+1)
    {
        cin>>v[i];
        v[i]-=k;
    }
    sum[0]=0;
    map<ll,ll> mapa;
    ordered_set S;
    
    S.insert(mp(0,mapa[0]++));
    ll tot=0;
    forr(i,1,n+1)
    {
        sum[i]=sum[i-1]+v[i];
        tot+=S.order_of_key({sum[i]+1,-1});
        S.insert({sum[i],mapa[sum[i]]++});
    }
    cout<<tot<<endl;
}
// PLUS ULTRA!ac