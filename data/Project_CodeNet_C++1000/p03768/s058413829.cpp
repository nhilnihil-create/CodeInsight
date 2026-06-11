#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

#define N 100005
#define D 11
vector<int> adj[N];
int timeT[N][D];

int color[N];
void solve() {
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;++i) {
    int a,b;scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int q;scanf("%d",&q);
  for(int timeS=1;timeS<=q;++timeS) {
    int v,d,c;scanf("%d %d %d",&v,&d,&c);
    timeT[v][d] = timeS;
    color[timeS] = c;
  }
  for(int timeS=10;timeS>=1;--timeS) {
    for(int i=1;i<=n;++i) {
      if(timeT[i][timeS]) {
        int sz= adj[i].size();
        int color = timeT[i][timeS];
        for(int j = 0;j<sz;++j) {
          timeT[adj[i][j]][timeS-1] = max(timeT[adj[i][j]][timeS-1], color);
        }
      }
    }
  }
  for(int i=1;i<=n;++i) {
    int maxTime = 0;
    for(int j =0;j<=10;++j) {
      maxTime = max(maxTime, timeT[i][j]);
    }
    printf("%d ",color[maxTime]);
  }
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
