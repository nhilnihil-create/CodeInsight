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

vector<vector<pair<int,int>>> edge(110);
vin d(110);

void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    fill(all(d),inf);
    d[s]=0;
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
    int n,m;cin>>n>>m;
    int a,b,c;
    rep(i,m){
        cin>>a>>b>>c;
        edge[a].push_back(mp(b,c));
        edge[b].push_back(mp(a,c));
    }
    int ans=0;
    rep2(i,1,n+1){
        dijkstra(i);
        for(auto e:edge[i]){
            if(d[e.first]!=e.second)ans++;
        }
    }
    cout<<ans/2<<endl;
}