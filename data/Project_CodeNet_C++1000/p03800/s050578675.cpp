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
typedef pair<int, int>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = ll(1e9+7);
#define tam 320000
#define tamlog 61
#define ptr nodo*

typedef pair<ii,ll> iii;
bool say[tam],resp[tam];
int main()
{
    int n;
    cin>>n;
    string txt;
    cin>>txt;
    forr(i,0,n)
    {
        if (txt[i]!='o')
            say[i]=1;
        else
            say[i]=0;
    }
    forr(j,0,4)
    {
        resp[0]=j&1;
        resp[1]=j&2;
        bool valcond=(resp[0]^say[0])^resp[1];
        forr(i,2,n)
        {
            bool valsay=(resp[i-1]^(say[i-1]))^resp[i-2];
            resp[i]=valsay;
        }
        if (resp[n-1]==valcond && resp[n-1]^say[n-1]==resp[0]^resp[n-2])
        {
            forr(i,0,n)
            {
                if (resp[i]==0)
                    cout<<"S";
                else
                    cout<<"W";
            }
            return 0;
        }
    }
    cout<<"-1\n";
}
// PLUS ULTRA!