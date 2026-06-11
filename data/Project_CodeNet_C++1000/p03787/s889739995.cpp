#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct ta{
  int num;
  int eo;
  int parent;
};

int main(){
  LL n,m;
  cin >> n >> m;
  vector<list<int>> e(n);
  int u,v;
  for(int i=0;i<m;i++){
    cin >> u >> v;
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<int> searched(n,-1);
  queue<struct ta> bfs;
  struct ta now;
  LL nibu=0,notnibu=0,ikko=0;
  int count=0;
  bool isnibu;
  for(int i=0;i<n;i++){
    if(searched[i]==-1){
      isnibu=true;
      searched[i]=0;
      bfs.push({i,0,-1});
      count=0;
      while(!bfs.empty()){
        count++;
        now=bfs.front();
        bfs.pop();
        for(auto itr=e[now.num].begin();itr!=e[now.num].end();itr++){
          if(searched[(*itr)]==-1){
            searched[(*itr)]=1-now.eo;
            bfs.push({(*itr),1-now.eo,now.num});
          }else if(searched[(*itr)]==now.eo){
            isnibu=false;
          }
        }
      }
      if(count==1) ikko++;
      else if(isnibu) nibu++;
      else notnibu++;
    }
  }
  // cout << ikko << nibu << notnibu << endl;
  cout << 2*ikko*n-ikko*ikko+(nibu+notnibu)*(nibu+notnibu)+nibu*nibu << endl;
  return 0;
}
