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

void ok(){
  cout << "YES" << endl;
  exit(0);
}

void ng(){
  cout <<  "NO" << endl;
  exit(0);
}

vector<Int> edge[216000];
Int deg[216000];
Int A[216000];
Int a, b, n;

int dfs(int x, int last = -1){
  if(deg[x] == 1)return A[x];
  Int mx = 0;
  Int sum = 0;
  for(auto to: edge[x]){
    if(to == last)continue;
    Int u = dfs(to, x);
    mx = max(mx, u);
    sum += u;
  }
  Int flip = sum - A[x];
  Int res = sum - 2 * flip;
  if(flip < 0)ng();
  if(flip > min(sum - mx, sum / 2))ng();
  if(res < 0)ng();
  return res;
}


int main(){
  cin >> n;
  for(int i = 0;i < n;i++)cin >> A[i];
  for(int i = 0;i < n-1;i++){
    cin >> a >> b;a--,b--;
    deg[a]++, deg[b]++;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  if(n == 2){
    if(A[0] == A[1])ok();
    else ng();
  }
  int root = 0;
  while(deg[root] == 1)root++;
  if(dfs(root) == 0)ok();
  ng();
  return 0;
}