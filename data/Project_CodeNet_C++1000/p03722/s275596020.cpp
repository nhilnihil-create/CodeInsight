#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,M;
struct Edge{
    ll from,to,cost;
};
vector<Edge> edgeList;
ll dist[1010];
ll pre[1010];

bool checked[1010]={};
bool Closed(ll n){
    if(checked[n]){
        return true;
    }
    checked[n]=true;
    if(n==0 && pre[0]==0) return false;
    return Closed(pre[n]);
}
int main(){
    cin>>N>>M;
    for(ll i=0;i<M;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        edgeList.push_back(Edge{a,b,-c});
    }
    for(ll i=0;i<N;i++)dist[i]=INF;
    dist[0]=0;
    for(ll i=0;i<N;i++){
        for(auto e:edgeList){
            if(dist[e.to]>dist[e.from]+e.cost){
                dist[e.to]=dist[e.from]+e.cost;
                pre[e.to]=e.from;
            }
        }
    }
    if(Closed(N-1)){
        cout<<"inf"<<endl;
        return 0;
    }
    cout<<-dist[N-1]<<endl;
    return 0;
}