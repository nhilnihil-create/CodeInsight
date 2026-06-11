#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

std::vector<ll> Color(200000, 0), max_d(200000, -1);
vvl edge = vv(200000, 0, 0, ll);
void dfs(ll now, ll d, ll c){
  if(max_d[now]>=d) return;
  //std::cout << now << " " << d  << " "<< c << '\n';
  if(Color[now]==0) Color[now] = c;
  max_d[now] = d;
  for(int i=0;i<edge[now].size();i++) if(d>0) dfs(edge[now][i], d-1, c);
}
int main(int argc, char const *argv[]) {
  ll N, M, Q, a, b;
  std::cin >> N >> M;
  for(int i=0;i<M;i++) {
    std::cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  std::cin >> Q;
  vvl query = vv(Q, 3, 0, ll);
  for(int q=0;q<Q;q++) std::cin >> query[q][0] >> query[q][1] >> query[q][2];
  for(int q=Q-1;q>=0;q--) dfs(query[q][0], query[q][1], query[q][2]);
  for(int i=1;i<=N;i++) std::cout << Color[i] << '\n';
  return 0;
}
