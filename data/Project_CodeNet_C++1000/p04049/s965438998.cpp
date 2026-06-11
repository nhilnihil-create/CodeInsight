#include <bits/stdc++.h>
typedef long long       ll;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define fore(i, b, e)      for(int i = b; i < e; i++)
#define forr(i, b, e)      for(int i = b; i < e; i++)
#define forg(i, b, e, m)  for(int i = b; i < e; i+=m)
#define fi first
#define se second
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef pair<int, ii>  iii;
typedef vector<int>     vi;

typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double PI = acos(-1);
const double EPS = 1e-9;
#define tam 1234567
vector<int> g[tam];
int valor[tam];
void add(int &iz,int &der)
{
    g[iz].pb(der);
    g[der].pb(iz);
}
int dfs(int num,int pa,int dia)
{
    if (dia<0)
        return 0;
    int res=valor[num];
    for(int v:g[num])
    {
        if (v==pa)continue;
        res+=dfs(v,num,dia-1);
    }
    return res;
}
int main()
{
    int  n,k;
    cin>>n>>k;
    forr(i,0,n+1)
    valor[i]=1;
    int auxx=n+1,iz,der;
    forr(i,0,n-1)
    {
        cin>>iz>>der;
        if (k&1)
        add(iz,auxx),add(auxx,der);
        else
        add(iz,der);
        auxx++;
    }
    int maxx=0;
    if (k&1)
    {
        forr(i,n+1,auxx)
        {
            maxx=max(maxx,dfs(i,i,k));
        }
    }
    else
    {
        forr(i,1,n+1)
        {
            maxx=max(maxx,dfs(i,i,k/2));
        }
    }
    cout<<n-maxx<<endl;
}
// PLUS ULTRA!