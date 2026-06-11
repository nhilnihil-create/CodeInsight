#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
using namespace std;

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

struct hen{
  int num;
  int color;
};

int main(){
  int n;
  cin >> n;
  vector<list<int>> e = vector<list<int>>(n,list<int>());
  int a,b;
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  queue<struct hen> bfs;
  vector<int> flag(n,0);
  struct hen now;

  bfs.push({0,1});
  bfs.push({n-1,2});
  flag[0]=1;
  flag[n-1]=2;
  while(!bfs.empty()){
    now=bfs.front();
    bfs.pop();
    for(list<int>::iterator itr=e[now.num].begin();itr!=e[now.num].end();itr++){
      if(!flag[(*itr)]){
        bfs.push({(*itr),now.color});
        flag[(*itr)]=now.color;
      }
    }
  }
  int f=0,s=0;
  for(int i=0;i<n;i++){
    if(flag[i]==1){
      f++;
    }else {
      s++;
    }
  }
  cout << (f>s?"Fennec":"Snuke") << endl;
  return 0;
}
