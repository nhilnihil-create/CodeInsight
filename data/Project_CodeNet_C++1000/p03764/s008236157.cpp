#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define forr(i, b, e)     for (int i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
#define tam 100056
#define offset 10000000
typedef pair<int,short> par;
const int MOD=1e9+7;
ll vx[tam],vy[tam],sumx[tam],sumy[tam];
void MODUL(ll &num)
{
    num%=MOD;
    num+=MOD;
    num%=MOD;
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin>>n>>m;
    forr(i,0,n)
    {
        cin>>vx[i];
    }    
    forr(i,0,m)
    {
        cin>>vy[i];
    }
    
    ll ant=0;
    for(int i=m-1;i>=0;i--)
    {
        sumy[i]=ant+vy[i];
        MODUL(sumy[i]);
        ant=sumy[i];
        //cout<<sumy[i]<<' ';
    }
    //cout<<endl;
    ant=0;
    for(int i=n-1;i>=0;i--)
    {
        sumx[i]=ant+vx[i];
        MODUL(sumx[i]);
        ant=sumx[i];
        //cout<<sumx[i]<<' ';
    }
    //cout<<endl;
    ll toty,respuesta,totx;
    toty=respuesta=0;
    forr(i,0,m)
    {
        toty+=sumy[i]-(m-i)*vy[i];
        MODUL(toty);
    }
    
    forr(i,0,n)
    {
        totx=sumx[i]-(n-i)*vx[i];
        MODUL(totx);
        respuesta+=(toty*totx)%MOD;
        MODUL(respuesta);
    }
    respuesta+=MOD;respuesta%=MOD;
    cout<<respuesta<<"\n";
}
// PLUS ULTRA!