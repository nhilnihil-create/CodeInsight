#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define forr(i, b, e)     for(ll i = b; i < e; i++)
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
const ll INF = ll(1e18);
#define tam 320000
#define tamlog 61
#define ptr nodo*

typedef pair<ii,ll> iii;
int sum[tam];
void update(int pos,int valor)
{
    for(int i=pos;i<tam;i+=(i&-i))
    {
        sum[i]+=valor;
    }
}
int query(int pos)
{
    int tot=0;
    for(int i=pos;i>0;i-=(i&-i))
        tot+=sum[i];
    return tot;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);    
    int n,m;
    cin>>n>>m;
    vector<ii> lst;
    int iz,der;
    forr(i,0,n)
    {
        cin>>iz>>der;
        lst.pb(ii(der-iz,iz));
    }
    sort(lst.begin(),lst.end());
    int pos=0;
    forr(d,1,m+1)
    {
        while(pos<lst.size() && lst[pos].F+1<d)
        {
            iz=lst[pos].S;
            der=iz+lst[pos].F;            
            update(iz,1);
            update(der+1,-1);
            pos++;
        }
        int auxans=lst.size()-pos;
        for(int j=d;j<=m;j+=d)
        {
            auxans+=query(j);
        }
        cout<<auxans<<endl;
    }


}
// PLUS ULTRA!