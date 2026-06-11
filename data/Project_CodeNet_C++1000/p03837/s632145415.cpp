#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
using t = tuple<int,int,int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
int n = 105;
int m = 1005;
map<P,int> mp;
vector<vector<P>> graph(n,vector<P>());
vector<bool> used(m,false);

int id(int i,int j){
    if(i > j) swap(i,j);
    return mp[P(i,j)];
}

void Dijkstra(int start){
    vector<bool> seen(n,false);
    vector<int> shoretest(n,0);
    priority_queue<t,vector<t>,greater<t>> pq;
    pq.push(t(0,start,-1));

    while(!pq.empty()){
        int dist = get<0>(pq.top());
        int v = get<1>(pq.top());
        int before = get<2>(pq.top());
        pq.pop();
        
        if(seen[v] && dist == shoretest[v]) used[id(before,v)] = true;
        if(seen[v]) continue;

        if(before!=-1){
            used[id(before,v)] = true;
        }
        shoretest[v] = dist;
        seen[v] = true;

        for(P next:graph[v]){
            int next_node = next.second;
            int next_cost = next.first;
            if(seen[next_node]) continue;
            pq.push(t(next_cost + dist,next_node,v));
        }
    }

    return ;
}

int main(){
    cin >> n >> m;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        graph[a].push_back(P(c,b));
        graph[b].push_back(P(c,a));
        if(a > b) swap(a,b);
        mp[P(a,b)] = i;
    }

    rep(i,n) Dijkstra(i);

    int ans = 0;
    rep(i,m){
        ans += !used[i];
    }

    cout << ans << endl;
    return 0;
}