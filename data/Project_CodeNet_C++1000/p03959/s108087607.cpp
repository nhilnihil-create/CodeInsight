#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, int> P;
typedef long long ll;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXV = 10000;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[ry]>rank[rx]) par[rx]=ry;
        else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};
int main(){
    int n;cin>>n;
    vector<ll> t(n),a(n);
    for(int i=0;i<n;++i) cin>>t[i];
    for(int i=0;i<n;++i) cin>>a[i];
    ll ans=1;
    bool flag=true;
    for(int i=0;i<n;++i){
        if(i==0||t[i-1]<t[i]){
            if(a[i]>a[i+1]){
                if(t[i]!=a[i]) flag=false;
            }else{
                if(t[i]>a[i]) flag=false;
            }
        }else{
            if(i==n-1||a[i]>a[i+1]){
                if(t[i]<a[i]) flag=false;
            }else{
                ans=ans*min(t[i],a[i])%MOD;
            }
        }
    }
    if(!flag){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}