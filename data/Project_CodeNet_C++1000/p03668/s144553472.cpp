#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N;

vector<int> g[100010];
bool used[100010];

int dfs(int now){
    used[now]=true;
    int res=0;
    for(int i=0;i<g[now].size();i++){
        int next=g[now][i];
        if(used[next]) continue;

        res^=dfs(next);
    }
    return(res+1);
}

int main(){
  cin>>N;
  for(int i=1;i<N;i++){
      int x,y;
      cin>>x>>y;
      x--;
      y--;
      g[x].push_back(y);
      g[y].push_back(x);
  }

  used[0]=true;
  int ans=0;
  for(int i=0;i<g[0].size();i++){
      int grundy=dfs(g[0][i]);
      //grundy--;
      ans^=grundy;
  }

  if(ans==0) cout<<"Bob"<<endl;
  else cout<<"Alice"<<endl;

  return 0;
}
