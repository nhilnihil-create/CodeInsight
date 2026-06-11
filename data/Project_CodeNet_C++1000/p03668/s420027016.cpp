#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int x[110000],y[110000];
vint G[110000];
int dfs(int from, int to) {
    int cur = 0;
    for (int i=0;i<G[to].size();i++){
      if(G[to][i]==from)continue;
      cur^=dfs(to,G[to][i])+1;
    }
    return cur;
}

signed main() {
  cin >> N;
  for(int i=0;i<N-1;i++){
    cin>>x[i]>>y[i];
    G[x[i]].push_back(y[i]);
    G[y[i]].push_back(x[i]);
  }
  if(dfs(0,1)!=0)cout<<"Alice"<<endl;
  else cout<<"Bob"<<endl;
}
