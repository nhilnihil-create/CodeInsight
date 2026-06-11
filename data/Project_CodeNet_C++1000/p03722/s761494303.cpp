#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<tuple<int, int, ll> > edge(M);
  vector<vector<int> > edge1(N), edgeN(N);
  int A, B, C;
  for(int i=0;i<M;++i){
    cin>>A>>B>>C;
    A--;
    B--;
    edge[i] = make_tuple(A, B, -C);
    edge1[A].push_back(B);
    edgeN[B].push_back(A);
  }

  // 頂点1から到達できるか、頂点Nへ行けるかチェック
  bool reach1[N], reachN[N];
  for(int i=0;i<N;++i){
    reach1[i] = false;
    reachN[i] = false;
  }

  queue<int> que1, queN;
  que1.push(0);
  queN.push(N-1);
  int state;

  while(!que1.empty()){
    state = que1.front();que1.pop();
    if(reach1[state]==true) continue;
    reach1[state] = true;
    for(int i=0;i<edge1[state].size();++i){
      que1.push(edge1[state][i]);
    }
  }

  while(!queN.empty()){
    state = queN.front();queN.pop();
    if(reachN[state]==true) continue;
    reachN[state] = true;
    for(int i=0;i<edgeN[state].size();++i){
      queN.push(edgeN[state][i]);
    }
  }

  bool reach[N];
  for(int i=0;i<N;++i) reach[i] = reach1[i] & reachN[i];

  bool neg = false;
  ll dist[N];
  for(int i=0;i<N;++i){
    dist[i] = big;
  }
  dist[0] = 0;
  int from, to;
  ll score;
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      from = get<0>(edge[j]);
      to = get<1>(edge[j]);
      score = get<2>(edge[j]);
      if(reach[from]==false || reach[to]==false) continue;
      if(dist[to] > dist[from] + score) {
        dist[to] = dist[from] + score;
        if(i==N-1) neg = true;
      }
    }
  }
  if(neg) cout<<"inf"<<endl;
  else cout<<-dist[N-1]<<endl;
}

