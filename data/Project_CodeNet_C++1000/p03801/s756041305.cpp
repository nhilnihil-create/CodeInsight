#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define forr(i, b, e)     for(ll i = b; i < e; i++)
#define forite(i, b, e)    for(auto i = b; i!=e; i++)
#define forg(i, b, e, m)  for(ll i = b; i < e; i+=m)

#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;

typedef long long       ll;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = ll(1e9+7);
#define tam 320000
#define tamlog 61
#define ptr nodo*

typedef pair<ii,ll> iii;
ll resp[tam];
int  main()
{
    ll n;
    cin>>n;
    map<ll,ll> occur,minpos;
    ll valor;
    forr(i,0,n)
    {
        cin>>valor;
        if (occur[valor]==0)
            minpos[valor]=i;
        occur[valor]++;
    }
    occur[0]=0;
    minpos[0]=n+10;
    auto ite=occur.end();
    ll pos=tam;
    ll totoccur=0;
    do{
        //if (ite->F==0)break;
        ite--;
        
        pos=min(pos,minpos[ite->F]);
        auto ite2=ite;ite2--;
        totoccur+=ite->S;
        if (ite->F!=0)
        resp[pos]+=(ite->F-ite2->F)*totoccur;

    }while(ite!=occur.begin());
    forr(i,0,n)
    cout<<resp[i]<<endl;
}
// PLUS ULTRA!