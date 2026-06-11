#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

vector<int> res;
int n, m, a, b;
vector<int> edge[216000];
bool used[216000];

void dfs(int x){
  res.push_back(x);
  used[x] = true;
  for(auto v:edge[x]){
    if(used[v])continue;
    dfs(v);
    return;
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  int s = 1, g = edge[s][0];
  used[g] = true;
  dfs(s);
  for(int i = 0;i < res.size();i++){
    int k = res.size() - i - 1;
    if(i < k)swap(res[i], res[k]);
  }
  dfs(g);

  cout << res.size() << endl;
  for(auto v:res)cout << v << " ";cout << endl;
    
  return 0;
}