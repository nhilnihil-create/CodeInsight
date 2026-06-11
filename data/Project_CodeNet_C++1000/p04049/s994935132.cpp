#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

//_____________________________________________________________
const int MAX_NODE=1000000;

vvi G = vv(MAX_NODE, 0, 0, int);
int dfs(int from, int now){
  int ret = 0;
  for(int i=0;i<G[now].size();i++) {
    if(from == G[now][i]) continue;
    ret = max(ret, dfs(now, G[now][i])+1);
  }
  return ret;
}
int cut(int from, int now, int K, int d){
  int ret = (d>K?1:0);
  for(int i=0;i<G[now].size();i++){
    if(from==G[now][i]) continue;
    ret += cut(now, G[now][i], K, d+1);
  }
  return ret;
}
bool check(int now, int k){
  int f = 0, s = 0;
  for(int i=0;i<G[now].size();i++){
    int tmp = dfs(now, G[now][i])+1;
    if(f<tmp) s = f, f = tmp;
    else if(s<tmp) s = tmp;
  }
  return (f>=k/2+(k%2==1?1:0) && s>=k/2);
}
void treeDFS(int from, int current, int dist, int &maxDist, int &maxVertex) {
    if (dist > maxDist) maxDist = dist, maxVertex = current;
    for (auto to : G[current]) {
        if (to == from) continue;
        treeDFS(current, to, dist + 1, maxDist, maxVertex);
    }
}
int getTreeDiameter(int s) {
    int start = s, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    start = end, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    //printf("start: %d, end: %d, diameter: %d\n", start, end, maxDist);
    return maxDist;
}
int dfd(int from, int now, int d, int m){
  if(d==m) return 1;
  int ret = 0;
  for(int i=0;i<G[now].size();i++){
    if(from==G[now][i]) continue;
    ret += dfd(now, G[now][i], d+1, m);
  }
  return ret;
}
int addd(int now, int m){
  int ma = 0;
  for(int i=0;i<G[now].size();i++){
    int tmp = dfd(now, G[now][i], 1, m);
    ma = max(ma, tmp);
  }
  return ma;
}
//_____________________________________________________________
int main(int argc, char const *argv[]) {
  int N, K, a, b;
  std::cin >> N >> K;
  for(int i=0;i<N-1;i++){
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  if(getTreeDiameter(1)<=K){
    std::cout << 0 << '\n';
    return 0;
  }
  int ans = 1000000007;
  for(int i=1;i<=N;i++){
    if(check(i, K)){
      int ad = (K%2==0?0:addd(i, (K+1)/2));
      ans = min(ans, cut(-1, i, K/2, 0)-ad);
    }
  }
  std::cout << ans << '\n';
  return 0;
}
