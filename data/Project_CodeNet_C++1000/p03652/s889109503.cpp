#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N,M;
  cin>>N>>M;
  vector<vector<int>> v(N,vector<int>(M));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      int x;
      cin>>x;
      v[i][j]=x-1;
    }
  }
  unordered_map<int,bool> m;
  int ans = INF;
  for(int i = 0; i < M; i++) m[i]=true;
  for(int i = 0; i < M; i++){
    vector<int> w(M,0);
    for(int j = 0; j < N; j++){
      for(int k = 0; k < M; k++){
        if(m[v[j][k]]){
          w[v[j][k]]++;
          break;
        }
      }
    }
    int p = 0;
    for(int j = 0; j < M; j++) chmax(p,w[j]);
    for(int j = 0; j < M; j++){
      if(w[j]==p) {
        m[j]=false;
        break;
      }
    }
    chmin(ans,p);
  }
  cout<<ans<<endl;
}