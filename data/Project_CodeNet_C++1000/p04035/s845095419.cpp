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
    int n,l;cin>>n>>l;
    vector<ll> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;++i){
        if(a[i-1]+a[i]>=l){
            cout<<"Possible"<<endl;
            for(int j=1;j<i;++j){
                cout<<j<<endl;
            }
            for(int j=n-1;j>=i;--j){
                cout<<j<<endl;
            }
            return 0;
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}