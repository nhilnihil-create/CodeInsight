#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
#include <cassert>
#include <complex>
using namespace std;
//#define N (1000000000+7)
//#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> Q;

struct edge
{
    int to;
    ll cost;
};

vector<edge>g[105];
int main() {
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,int>mp;
    set<int>ans;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        pair<int,int> p = make_pair(a,b);
        mp[p]=i;
    }
    for(int st=0;st<n;st++){
        for(int go=st+1;go<n;go++){
            vector<ll>dist(n,(ll)INF);
            vector<bool>visited(n);
            vector<int>prever(n,-1);
            priority_queue<P,vector<P>,greater<P>>pq;
            dist[st]=0;
            pq.push(P(st,0));
            while(!pq.empty()){
                P p = pq.top();
                pq.pop();
                int now = p.first;
                int d = p.second;
                if(dist[now]<d)continue;
                for(int i=0;i<g[now].size();i++){
                    edge e = g[now][i];
                    int to = e.to;
                    ll cost = e.cost;
                    if(dist[to]>dist[now]+cost){
                        dist[to]=dist[now]+cost;
                        prever[to]=now;
                        pq.push(P(to,dist[to]));
                    }
                }
            }
            int t = go;
            for(;t!=-1;t=prever[t]){
                int v = prever[t];
                pair<int,int> p1 = make_pair(v,t);
                pair<int,int> p2 = make_pair(t,v);
                if(mp.find(p1)!=mp.end()){
                    ans.insert(mp[p1]);
                    continue;
                }
                if(mp.find(p2)!=mp.end()){
                    ans.insert(mp[p2]);
                    continue;
                }
            }
        }
    }
    cout<<m-ans.size()<<endl;
}
