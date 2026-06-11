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
vector<ll> A;
vector<int> g[100010];
bool used[100010];
ll path[100010];

bool dfs(int now){
    used[now]=true;
    ll sum=0;
    bool leaf=true;
    vector<int> next;
    for(int i=0;i<g[now].size();i++){
        int u=g[now][i];
        if(used[u]) continue;
        if(!dfs(u)) return false;
        sum+=path[u];
        leaf=false;
        next.push_back(u);
    }
    if(leaf){
        path[now]=A[now];
        return true;
    }

    ll res=2*A[now]-sum;
    path[now]=res;
    if(res<0) return false;

    ll tmp=res+sum;
    if(tmp%2||res*2>tmp) return false;
    for(int i=0;i<next.size();i++){
        if(path[next[i]]*2>tmp) return false;
    }
    return true;
}

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
      ll x;
      cin>>x;
      A.push_back(x);
  }
  for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
  }

  int start=0;
  for(int i=0;i<N;i++){
      if(g[i].size()==1) start=i;
  }

  if(!dfs(start)) cout<<"NO"<<endl;
  else{
      if(path[start]==A[start]) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  }

  return 0;
}
