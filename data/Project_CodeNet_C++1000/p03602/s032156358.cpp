

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/

/////////////////////////////////
#define MAX_N 305//調節！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
int par[MAX_N],dep[MAX_N];//depはrankのこと
//n要素で初期化//忘れないように！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
void init(int n){
    for(int i=0;i<=n-1;i++){//頂点番号は0~n-1
        par[i]=i;
        dep[i]=0;
    }
}
//木の根を求める
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
//xとyの属する集合を併合
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(dep[x]<dep[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(dep[x]==dep[y])dep[x]++;
    }
}
//xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x)==find(y);
}

//////////////////////////////////////

ll INF=30000000005;

struct edge {
    int from,to;
    ll cost;
    
    bool operator<( const edge& right ) const {
        return cost < right.cost;
    }
};
int n;
vector<i_i>v[MAX_N];
ll dis(int s,int t){
    ll mind[n];for(int i=0;i<=n-1;i++)mind[i]=INF;
    mind[s]=0;
    queue<ll>q;q.push(s);
    while(!q.empty()){
        ll top=q.front();q.pop();
        for(auto x:v[top]){
            ll y=x.first,dist=x.second;
            if(dist+mind[top]<mind[y]){
                mind[y]=mind[top]+dist;
                q.push(y);
            }
        }
    }
    return mind[t];
}

int main(){
    cin>>n;
    init(n);
    vector<edge> e;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            ll c;cin>>c;
            if(i<j)e.push_back(edge{i,j,c});
        }
    }
    sort(e.begin(),e.end());
    ll ans=0;
    for(auto x:e){
        ll s=x.from,t=x.to,c=x.cost;
        if(same(s,t)){
            ll d=dis(s,t);
            if(d<c){
                cout<<-1<<endl;
                return 0;
            }else if(d>c){
                v[s].push_back(make_pair(t,c));
                v[t].push_back(make_pair(s,c));
                ans+=c;
            }
        }else{
            v[s].push_back(make_pair(t,c));
            v[t].push_back(make_pair(s,c));
            ans+=c;
            unite(s,t);
        }
    }
    cout<<ans<<endl;
    return 0;
}
