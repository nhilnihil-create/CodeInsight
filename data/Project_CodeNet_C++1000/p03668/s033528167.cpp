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

vvi G = vv(100001, 0, 0, int);
int dfs(int from, int now){
  int ret = 0;
  if((from==-1&&G[now].size()==1)||(from!=-1&&G[now].size()==2)){
    for(int i=0;i<G[now].size();i++){
      if(G[now][i]==from) continue;
      ret = dfs(now, G[now][i]) + 1;
    }
  }
  else{
    for(int i=0;i<G[now].size();i++){
      if(from==G[now][i]) continue;
      ret ^= (dfs(now, G[now][i])+1);
    }
  }
  return ret;
}
int main(int argc, char const *argv[]) {
  int N, a, b;
  std::cin >> N;
  for(int i=0;i<N-1;i++){
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  std::cout << (dfs(-1, 1)==0?"Bob":"Alice")<< '\n';
  return 0;
}
