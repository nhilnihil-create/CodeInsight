#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N,M;
vector<int> A,B;

vector<int> g[100010];
vector<int> ans,res;
int used[100010];

void dfs(int now){
    used[now]=1;
    ans.push_back(now);
    for(auto nex:g[now]){
        if(used[nex]==0){
            dfs(nex);
            return;
        }
    }
}

void rfs(int now){
    used[now]=1;
    res.push_back(now);
    for(auto nex:g[now]){
        if(used[nex]==0){
            rfs(nex);
            return;
        }
    }
}

int main(){
  cin>>N>>M;
  A.resize(M);
  B.resize(M);
  rep(i,M){
      cin>>A[i]>>B[i];
      A[i]--;
      B[i]--;
      g[A[i]].push_back(B[i]);
      g[B[i]].push_back(A[i]);
  }

  dfs(0);
  rfs(0);

  reverse(res.begin(),res.end());
  res.pop_back();
  for(int i=0;i<ans.size();i++) res.push_back(ans[i]);

  cout<<res.size()<<endl;
  for(auto n:res) cout<<n+1<<" ";
  cout<<endl;

  return 0;
}
