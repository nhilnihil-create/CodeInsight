#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n,m,q;
  cin >> n >> m;
  vector<list<int>> e(n,list<int>());
  int a,b;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  cin >> q;
  int v,d,c;
  vector<vector<int>> query(n,vector<int>(11,0));
  vector<int> color(q+1);
  color[0]=0;
  for(int t=1;t<=q;t++){
    cin >> v >> d >> color[t];
    v--;
    query[v][d]=max(query[v][d],t);
  }
  for(int i=10;i>0;i--){
    for(int j=0;j<n;j++){
      for(auto itr=e[j].begin();itr!=e[j].end();itr++){
        query[(*itr)][i-1]=max(query[(*itr)][i-1],query[j][i]);
      }
    }
  }
  int ma;
  for(int i=0;i<n;i++){
    ma=query[i][0];
    // cout << query[i][0] << " ";
    for(int j=1;j<11;j++){
      ma=max(ma,query[i][j]);
      // cout << query[i][j] << " ";
    }
    // cout << endl;
    cout << color[ma] << endl;
  }
  return 0;
}
