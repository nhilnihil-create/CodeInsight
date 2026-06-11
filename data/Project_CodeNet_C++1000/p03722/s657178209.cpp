#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

vector<ll> to[1010];
vector<ll> ot[1010];
bool ok1[1010];
bool ok2[1010];

void dfs(int s){
  if(ok1[s]) return;
  ok1[s] = true;
  for(int i = 0;i < to[s].size();i++){
    dfs(to[s][i]);
  }
}
 
void dfs2(int s){
  if(ok2[s]) return;
  ok2[s] = true;
  for(int i = 0;i < ot[s].size();i++){
    dfs2(ot[s][i]);
  }
}

int main(){
  ll N,M;cin >> N >> M;
  vector<tuple<ll,ll,ll>> edges;
  for(int i = 0;i < M;i++){
    int a,b,c;cin >> a >> b >> c;
    a--;b--;
    c = -c;
    to[a].push_back(b);
    ot[b].push_back(a);
    edges.emplace_back(a,b,c);
  }
  bool upd = true;
  vector<ll> d(N,INF);
  d[0] = 0;
  ll step = 0;
  vector<bool> NEG(N,0);
  vector<bool> ok3(1010);
  fill(ok1,ok1+1010,0);
  fill(ok2,ok2+1010,0);
  dfs(0);
  dfs2(N-1);
  for(int i = 0;i < 1010;i++){
    ok3[i] = ok1[i] & ok2[i];
  }
  while(upd){
    upd = false;
    for(int i = 0;i < M;i++){
      ll a,b,c;
      tie(a,b,c) = edges[i];
      if(!ok3[a] || !ok3[b]) continue;
      if(NEG[a]){
        NEG[b] = 1;
      }
      ll newD = d[a] + c;
      if(d[b] > newD){
        upd = true;
        d[b] = newD;
        NEG[b] = 1;
      }
    }
    step++;
    if(step > N){
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << -d[N-1] << endl;
}