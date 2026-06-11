#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

map<ll, map<ll, ll> > G;
ll N, M;
ll INF = (ll)pow(10, 9);

void dijkstra(ll st, vvl &dist){
  priority_queue<pll> que;
  ll x, y, w;

  rep2(i, 1, N + 1) que.push(make_pair(dist[st][i], i));
  
  while(!(que.empty())){
    w = que.top().first;
    x = que.top().second;
    
    que.pop();
    
    for(auto itr = G[x].begin(); itr != G[x].end(); itr++){
      y = itr->first;
      ll alt = dist[st][x] + G[x][y];

      if(dist[st][y] > alt){
        dist[st][y] = alt;
        que.push(make_pair(alt, y));
      }
    }
  }
}

int main(){
  cin >> N >> M;
  
  ll a, b, c;
  vpll edge(M);
  rep(i, M){
    cin >> a >> b >> c;

    G[a][b] = c;
    G[b][a] = c;
    edge[i] = make_pair(a, b);
  }

  vvl dist(N + 1, vl(N + 1, INF));
  rep2(i, 1, N + 1) dist[i][i] = 0;
  
  rep2(i, 1, N + 1) dijkstra(i, dist);
  
  ll cnt = 0;

  rep(i, M){
    a = edge[i].first;
    b = edge[i].second;
    c = G[a][b];
    
    rep2(j, 1, N + 1){      
      if(dist[j][a] + c == dist[j][b]){
        cnt++;
        break;
      }
    }
  }

  cout << M - cnt << endl;
  
  return 0;
}