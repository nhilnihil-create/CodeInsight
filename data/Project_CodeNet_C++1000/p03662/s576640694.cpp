/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 100000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

vector<int> edges[MAX_N];
int n;

bool dfs(vector<bool> &used, int v){
  if(v==n-1)return used[v]=true;
  for(auto &e: edges[v]){
    if(used[e])continue;
    used[e]=true;
    if(dfs(used, e))return true;
    used[e]=false;
  }
  return false;
}

int main(){
  cin>>n;
  rep(i, n-1){
    int a, b;cin>>a>>b;
    a--;b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  vector<int> fennec(n, -1), snuke(n, -1);
  queue<P> que;
  que.push(P(0, 0));fennec[0]=0;
  while(que.size()){
    P p=que.front();que.pop();
    for(auto &e: edges[p.first]){
      if(fennec[e]!=-1)continue;
      fennec[e]=p.second+1;
      que.push(P(e, p.second+1));
    }
  }
  que.push(P(n-1, 0));snuke[n-1]=0;
  while(que.size()){
    P p=que.front();que.pop();
    for(auto &e: edges[p.first]){
      if(snuke[e]!=-1)continue;
      snuke[e]=p.second+1;
      que.push(P(e, p.second+1));
    }
  }
  int fcnt=0, scnt=0;
  rep(i, n){
    if(fennec[i]<=snuke[i])fcnt++;
    else scnt++;
  }
  cout<<(fcnt>scnt?"Fennec":"Snuke")<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
