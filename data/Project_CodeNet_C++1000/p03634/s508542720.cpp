#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

vector<vector<pair<ll,ll>>> edge(100050);
vll d(100050);

void dijkstra(ll s){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    fill(all(d),INF);
    d[s]=(ll)0;
    q.push(mp(0,s));
    while(q.size()){
        auto p=q.top();q.pop();
        auto v=p.second;
        if(d[v]<p.first)continue;
        for(auto e:edge[v]){
            if(d[e.first]>d[v]+e.second){
                d[e.first]=d[v]+e.second;
                q.push(mp(d[e.first],e.first));
            }
        }
    }
}

int main(){
    int n;cin>>n;
    ll a,b,c;
    rep(i,n-1){
        cin>>a>>b>>c;
        edge[a].push_back(mp(b,c));
        edge[b].push_back(mp(a,c));
    }
    int q,k;cin>>q>>k;
    dijkstra(k);
    int x,y;
    vll ans(q);
    rep(i,q){
        cin>>x>>y;
        ans[i]=d[x]+d[y];
    }
    rep(i,q)cout<<ans[i]<<endl;
}