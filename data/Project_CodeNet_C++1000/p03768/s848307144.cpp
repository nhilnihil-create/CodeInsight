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

int N,M,Q;
vector<int> A,B,C,D,V;

vector<int> g[100010];
int color[100010];
int visited[100010];

int main(){
  cin>>N>>M;
  A.resize(M);
  B.resize(M);
  rep(i,M) cin>>A[i]>>B[i];
  cin>>Q;
  C.resize(Q);
  D.resize(Q);
  V.resize(Q);
  rep(i,Q) cin>>V[i]>>D[i]>>C[i];

  rep(i,M){
    A[i]--;B[i]--;
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);
  }
  rep(i,N) visited[i]=-1;

  for(int i=Q-1;i>=0;i--){
    V[i]--;
    if(visited[V[i]]>=D[i]) continue;

    queue<int> Q;
    Q.push(V[i]);
    visited[V[i]]=D[i];
    while(!Q.empty()){
      int now=Q.front();
      Q.pop();

      if(color[now]==0) color[now]=C[i];
      if(visited[now]==0) continue;

      for(auto nex:g[now]){
        if(visited[nex]>=visited[now]-1) continue;
        visited[nex]=visited[now]-1;
        Q.push(nex);
      }
    }
  }

  for(int i=0;i<N;i++) cout<<color[i]<<endl;


  return 0;
}
