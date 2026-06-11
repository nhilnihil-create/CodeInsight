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

std::vector<int> G(100001);
vvi rev = vv(100001, 0, 0, int);
int ans = 0;
priority_queue<pair<int, int> > q;
std::vector<int> ok(100001, 0);
void dfs(int now, int d){
  if(rev[now].size()==0) q.push(make_pair(d, now));
  for(int i=0;i<rev[now].size();i++){
    if(rev[now][i]==now) continue;
    dfs(rev[now][i], d+1);
  }
}
void check(int now, int m, int d, int d2){
  if(ok[now]==1||now==1) return;
  if(d==0){
    ans++,q.push(make_pair(m-d2, now));
    return;
  }
  ok[now] = 1;
  check(G[now], m, d-1, d2);
}
int main(int argc, char const *argv[]) {
  int N, K, a;
  std::cin >> N >> K;
  for(int i=1;i<=N;i++){
    std::cin >> a;
    if(i==1&&a!=1) ans++, a=1;
    G[i]=a;
    rev[a].push_back(i);
  }
  dfs(1, 0);
  while(!q.empty()){
    int x = q.top().first, y=q.top().second;
    //std::cout << x << " " << y << '\n';
    q.pop();
    check(y, x, K, K);
  }
  std::cout << ans << '\n';
  return 0;
}
