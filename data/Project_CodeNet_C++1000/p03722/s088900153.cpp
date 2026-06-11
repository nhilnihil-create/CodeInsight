#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const long long INF = 10100100100100;
using namespace std;

int N, M;

typedef struct Edge{
  int from;
  int to;
  int w;
} Edge;

long long d[1100];
Edge edges[2100];

int main()
{
  cin >> N >> M;

  rep(i,M){
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    edges[i] = {a,b,-c};
  }


  rep(i,N) d[i]= INF;
  d[0] = 0;
  int count = 0;
  
  rep(i,N) {
    for(auto it: edges){
      int from = it.from;
      int to = it.to;
      int w = it.w;
      if(d[from] != INF && d[to] > d[from] + w){
        d[to] = d[from] + w;
      }
    }
  }

  bool negative[1100];
  rep(i,N) negative[i] = false;

  rep(i,M) {
    Edge e = edges[i];
    if(d[e.to] > d[e.from] + e.w){
      d[e.to] = d[e.from] + e.w;
      negative[e.to] = true;
    }
  }

  if(negative[N-1]) cout << "inf" << endl;
  else cout << -d[N-1] << endl;
  return 0;
}
