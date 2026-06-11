#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=1e9;
const ll MOD=1e9+7;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n,0){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[rx]>rank[ry]) par[ry]=rx;
        else par[rx]=ry;
        if(rank[rx]==rank[ry]) rank[ry]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int cnt(int n){
        int res=0;
        for(int i=0;i<n;++i){
            if(root(i)==i) res++;
        }
        return res;
    }
};

ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%MOD;
        a=a*a%MOD;
        x>>=1;
    }
    return res;
}
int main(){
    int N;cin>>N;
    map<int,int> mp;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        mp[a]++;
    }
    int ans=0;
    for(auto it:mp){
        if(it.second%2==1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}