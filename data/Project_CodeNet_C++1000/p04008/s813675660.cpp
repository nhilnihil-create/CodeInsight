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
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;


vector<Int> rev[108000];
Int height[108000];
Int cnt;
Int n, k, a[108000];
void dfs(int x, int last = -1){
  height[x] = 0;
  for(auto to: rev[x]){
    if(to == last)continue;
    if(to == 1)continue;
    dfs(to, x);
    if(height[to] == k-1 && x != 1)cnt++;
    else height[x] = max(height[x], height[to] + 1);
  }
}

int main(){
  cin >> n >> k;
  for(int i = 1;i <= n;i++){
    cin >> a[i];
    rev[a[i]].push_back(i);
  }
  if(a[1] != 1){
    a[1] = 1;
    cnt++;
  }

  dfs(1);
  cout << cnt << endl;
  
  return 0;
}