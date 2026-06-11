#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;


typedef pair<ll, pair<int, int>> P;
const ll INF = 1LL << 50;

int main(){
  int N;
  cin >> N;
  priority_queue<P, vector<P>, greater<P>> que;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int a;
      cin >> a;
      if(i > j) que.push(P(a, pair<int, int>(i, j)));
    }
  }

  ll d[N][N];
  fill(d[0], d[N], INF);
  for(int i = 0; i < N; i++) d[i][i] = 0;

  ll ans = 0;
  while(!que.empty()){
    P p = que.top();
    que.pop();

    ll cost = p.first;
    //a > b
    int a = p.second.first;
    int b = p.second.second;

    if(d[a][b] > cost){
      //cout << a << " " << b << " " << cost << endl;
      //a-bに辺を追加
      ans += cost;
      d[a][b] = cost;
      d[b][a] = cost;
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          d[i][j] = min(d[i][j], d[i][a] + cost + d[j][b]);
          d[j][i] = d[i][j];
        }
      }
    } else if(d[a][b] == cost){
      //何もしない
    } else {
      //構築不可能
      //cout << a << " " << b << " " << cost << endl;
      cout << -1 << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;
}
