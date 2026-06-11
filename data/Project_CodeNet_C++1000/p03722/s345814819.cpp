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
#include<tuple>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=1e3;
const int MAXM=2000;
const ll INF=1e18;

struct edge{
    int from,to;
    ll cost;
};

int n,m;
vector<edge> es(MAXM);
vector<ll> d(MAXN,-INF);

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        from--;to--;
        es[i]=edge{from,to,cost};
    }
   d[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            edge e=es[j];
            if(d[e.from]!=-INF&&d[e.to]<d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
            }
        }
    }
    ll ans=d[n-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            edge e=es[j];
            if(d[e.from]!=-INF&&d[e.to]<d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
            }
        }
    }
    if(ans!=d[n-1]) cout<<"inf"<<endl;
    else cout<<ans<<endl;
    return 0;
}