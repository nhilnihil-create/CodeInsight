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
#define tam 1003455

int v[tam];
int f(int y,int x,int yy,int xx)
{
    return (abs(y-yy)+abs(x-xx))%2==1;
}
int  main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    forr(i,1,n+1)
    cin>>v[i];
    sort(v+1,v+n+1);
    reverse(v+1,v+n+1);
    int x,y;
    x=y=1;
    forr(i,1,n+1)
    {
        if (y>v[i])break;
        y++;x++;
    }
    y--,x--;
    bool win=0;
    if (x<n)
    {
        int lst=0;
        forr(i,1,n+1)
        {
            if (y==v[i])
                lst=i;
        }
        if (lst!=0)
        win=f(y,x,v[lst],lst);
        if (v[x]!=y)
            win|=f(y,x,y,v[x]);

    }
    else
    {
        win=f(y,x,v[n],n);
    }
    if (win)
        cout<<"First\n";
    else
        cout<<"Second\n";
}
// PLUS ULTRA!!