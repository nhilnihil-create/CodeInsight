#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const ll mod=1000000007ll;
const ll inf=1000000000000000ll;

const ll nmax=2*100000+1;

//ll par[nmax];
//ll rank[nmax];

class unionfind{
public:
    ll par[nmax];
    ll rank[nmax];

    unionfind(ll n){
        for(ll i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }

    ll root(ll x){
        if(par[x]==x)return x;
        else return par[x]=root(par[x]);
    }

    void unite(ll x,ll y){
        x=root(x);
        y=root(y);
        if(x==y) return;

        if(rank[x]<rank[y]) par[x]=y;
        else{
            par[y]=x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }

    bool same(ll x,ll y){
        return root(x)==root(y);
    }
};

int main()
{
    ll n,k,l,p,q;
    cin>>n>>k>>l;
//    P roots[n];

    unionfind ro(n);
    unionfind te(n);

    for(ll i=0;i<k;i++){
        cin>>p>>q;
        ro.unite(p-1,q-1);
    }
    for(ll i=0;i<l;i++){
        cin>>p>>q;
        te.unite(p-1,q-1);
    }
    unordered_map<string,ll> mp;
    for(ll i=0;i<n;i++){
        mp[to_string(ro.root(i))+" "+to_string(te.root(i))]++;
    }
    for(ll i=0;i<n;i++){
        //cout<<i<<","<<ro.root(i)<<","<<te.root(i)<<endl;
        cout<<mp[to_string(ro.root(i))+" "+to_string(te.root(i))]<<" ";
    }
    cout<<endl;

    return 0;
}
