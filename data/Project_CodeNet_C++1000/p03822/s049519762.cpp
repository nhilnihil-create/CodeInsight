#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 5;

vector < vector < int > > adj(N, vector < int > ());
vector < int > depth(N);

void dfs(int u){
  depth[u] = 0;
  vector < int > v;
  for(auto to : adj[u]){
    dfs(to);
    v.push_back(depth[to]);
  }

  sort(v.begin(), v.end(), greater < int > ());
  for(int i = 0; i < v.size(); i++){
    depth[u] = max(depth[u], v[i] + i + 1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  for(int i = 2; i <= n; i++){
    int a;
    cin >> a;
    adj[a].push_back(i);
  }

  depth[1] = 0;
  dfs(1);

  cout << *max_element(depth.begin(), depth.end()) << '\n';
}
