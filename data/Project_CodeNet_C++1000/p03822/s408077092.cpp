#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const int n_max=1e5+5;
vector<int> g[n_max];
vector<int> ans;

int dfs(int v){
  vector<int> ans;
  for(auto i:g[v]){
    ans.pb(dfs(i));
  }
  if(g[v].empty()){
    ans.pb(0);
  }
  sort(ans.begin(),ans.end());
  int next=ans[0]+1;
  rep1(i,ans.size()-1){
    if(next>ans[i]){
      next++;
    }
    else{
      next=ans[i]+1;
    }
  }
  return next;
  
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  int a;
  rep1(i,n-1){
    cin >> a;
    a--;
    g[a].pb(i);
  }
  cout << dfs(0)-1 << endl;;
  

  return 0;
    

}
