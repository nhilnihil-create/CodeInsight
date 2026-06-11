#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using ll = long long;
using namespace std;
int dfs(vvi &dis,int R, vi &r, int pos, int current, vi checked){
  int best = 1000000000;
  rep(i, R){
    if(!checked[i]){
      checked[i] = 1;
      best = min(best, dfs(dis, R, r, i, current + dis[pos][r[i]], checked));
      checked[i] = 0;
    }
  }
  return (best == 1000000000) ? current : best;
}
int main(){
  int n,m,R;
  cin >> n >> m >> R;
  vi r(n);
  rep(i, R){
    cin >> r[i];
    r[i]--;
  }
  vector<vector<pii>> root(n);
  rep(i, m){
    int a,b,c; // 0 ~
    cin >> a >> b >> c;
    a--; b--;
    root[a].push_back(make_pair(b, c));
    root[b].push_back(make_pair(a, c));
  }
  vvi distance(R, vi(n, -1));
  rep(i, R){
    priority_queue<pii, vector<pii>, greater<pii>> que;
    // <最短距離, 頂点>
    que.push(make_pair(0, r[i])); //0 をスタート地点として距離を0とする
    distance[i][r[i]] = 0;
    while(!que.empty()){
      pii info = que.top();
      que.pop();
      int pos = info.second;
      if(distance[i][pos] < info.first) continue;
      for(pii x : root[pos]){
        int next = x.first;
        int kyori = x.second + distance[i][pos];
        if(distance[i][next] == -1 || distance[i][next] > kyori){
          que.push(make_pair(kyori, next));
          distance[i][next] = kyori;
        }
      }
    }
  }
  vi checked(R);
  int ans = 1000000000;
  rep(i, R){
    checked[i] = 1;
    ans = min(ans, dfs(distance, R, r, i, 0, checked));
    checked[i] = 0;
  }
  cout << ans << endl;
}