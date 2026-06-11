#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct b{
  int num;
  int c;
};

int main(){
  int n;
  cin >> n;
  vector<list<int>> e(n,list<int>());
  int a,b;
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  queue<struct b> bfs;
  vector<int> color(n,-1);
  bfs.push({0,0});
  bfs.push({n-1,1});
  struct b now;
  while(!bfs.empty()){
    now=bfs.front();
    bfs.pop();
    for(auto itr=e[now.num].begin();itr!=e[now.num].end();itr++){
      if(color[(*itr)]==-1){
        color[(*itr)]=now.c;
        bfs.push({(*itr),now.c});
      }
    }
  }
  int f=0,s=0;
  for(int i=0;i<n;i++){
    if(color[i]==0) f++;
    else s++;
  }
  cout << (f>s?"Fennec":"Snuke") << endl;
  return 0;
}
