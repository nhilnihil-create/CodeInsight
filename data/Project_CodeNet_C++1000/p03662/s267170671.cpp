#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define REPS(i,n) for(int i=1;i<=(n);i++)
#define RREPS(i,n) for(int i=(n);i>0;i--)
#define mp make_pair
#define pb(a) push_back(a)
typedef long long ll;

#define MAX_N 100000
vector<int> G[MAX_N];
int dis1[MAX_N];
int disN[MAX_N];
int N;
void dfs1(int n,int d = 0){
    dis1[n] = d;
    REP(i,G[n].size()){
      if(dis1[G[n][i]] == 0 && G[n][i] != 0) dfs1(G[n][i],d+1);
    }
}
void dfsN(int n,int d = 0){
    disN[n] = d;
    REP(i,G[n].size()){
      if(disN[G[n][i]] == 0 && G[n][i] != N-1) dfsN(G[n][i],d+1);
    }
}
int main(){

  cin >> N;
  REP(i,N-1){
    int a,b;
    cin >> a >> b;
    G[a-1].pb(b-1);
    G[b-1].pb(a-1);
  }
  dfs1(0);
  dfsN(N-1);
  int b = 0;
  int w = 0;
  REP(i,N){
    if(dis1[i] <= disN[i]) b++;
    else w++;
  }
  if(b > w) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
  return 0;
}
