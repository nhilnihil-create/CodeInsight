#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
#include <cstring>
#include <iomanip>
#include<queue>
#include<set>

using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1000000000
typedef long long  ll;

#define MOD 1000000007

int N,M;
vector<vector<int> > e;
vector<bool> used;
vector<int> ans;

void dfs(int s){
  ans.push_back(s+1);
  used[s] = true;
  REP(i,0,e[s].size()){
    int v = e[s][i];
    if(!used[v])
      return dfs(v);
  }
  return;
}

int main()
{
  cin >> N >> M;
  used.resize(N);
  e.resize(N);
  REP(i, 0, M)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  REP(i,0,N){
    used[i] = false;
  }

  dfs(0);
  reverse(ans.begin(),ans.end());
 ans.pop_back();
 dfs(0);
  cout << ans.size()<<endl;
  REP(i,0,ans.size()){
    cout << ans[i] << " ";
  }
}
