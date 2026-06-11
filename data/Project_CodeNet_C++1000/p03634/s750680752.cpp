#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;

  map<pii,int> m; // e_ij (i<j) の長さ 
  map<int, ll> dist; // Kからの距離

  for(int i = 0; i < N; i++){
    dist[i] = -1;
  }

  vector<vector<int>> v(N); // 隣接リスト

  for(int i = 0; i < N-1; i++){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    if(a>b) swap(a,b);

    m[make_pair(a,b)] = c;

    v.at(a).push_back(b);
    v.at(b).push_back(a);
  }

  int Q,K;
  cin >> Q >> K;
  K--;
  dist[K] = 0;

  queue<int> q;
  q.push(K);

  // cerr << K << endl;

  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(auto next: v.at(now)){
      if(dist[next] != -1){
        continue;
      } else { 
        int tmp_a,tmp_b;
        tmp_a = min(now,next);
        tmp_b = max(now,next);
        ll tmp_c = m[make_pair(tmp_a, tmp_b)];
        dist[next] = dist[now] + tmp_c;
        q.push(next);
      }
    }
  }

  // answer
  for(int i = 0; i < Q; i++){
    int x,y;
    cin >> x >> y;
    x--; y--;
    cout << dist[x] + dist[y] << endl;
  }
/* 
  for(auto x: dist){
    // cerr << "dist from K to " << x.first << " is " << x.second << endl;
  }
 */

}
