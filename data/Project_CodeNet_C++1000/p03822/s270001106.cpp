#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100015
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n;
vector<int> G[SIZE];

int dfs(int v){
  vector<int> a;
  for(auto to : G[v]){
    a.push_back(dfs(to));
  }
  int u = 0;
  sort(a.begin(),a.end(),greater<int>());
  rep(i,0,a.size()){
    u = max(u,a[i]+i+1);
  }
  return u;
}

int main(){
  cin >> n;
  rep(i,2,n+1){
    int a;
    cin >> a;
    G[a].push_back(i);
  }
  cout << dfs(1) << endl;

  return 0;
}
