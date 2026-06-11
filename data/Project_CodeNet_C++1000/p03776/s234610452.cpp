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
const ll INF = 1e18;
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
ll com[100][100];

void initcom(){
    com[0][0]=1;
    for(int i=1;i<100;++i){
        for(int j=0;j<=i;++j){
            if(j==0||j==i) com[i][j]=1;
            else com[i][j]=com[i-1][j-1]+com[i-1][j];
        }
    }
}

int main(){
    initcom();
    int n,a,b;cin>>n>>a>>b;
    vector<ll> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    sort(v.begin(),v.end(),greater<ll>());
    double avg=0;
    map<ll,int> cntv,cntavg;
    for(int i=0;i<n;++i){
        if(i<a){
            avg+=v[i];
            cntavg[v[i]]++;
        }
        cntv[v[i]]++;
    }
    avg/=(double)a;
    printf("%.14f\n",avg);
    if((int)cntavg.size()==1){
        b=min(b,cntv[v[0]]);
        ll ans=0;
        for(int i=a;i<=b;++i){
            ans+=com[cntv[v[0]]][i];
        }
        cout<<ans<<endl;
        return 0;
    }
    ll ans=1;
    for(auto it:cntavg){
        ans*=com[cntv[it.first]][it.second];
    }
    cout<<ans<<endl;
    return 0;
}