#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pil = pair<int, long>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007
#define INF 1e17

struct edge{
  int from;
  int to;
  long cost;
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<edge> edges(m);
  rep(i,m){
    cin >> edges.at(i).from >> edges.at(i).to >> edges.at(i).cost;
    edges.at(i).from--;
    edges.at(i).to--;
  }
  vector<long> d(n,-1*INF);
  d.at(0) = 0;
  rep(i,n){
    rep(j,m){
      struct edge e;
      e = edges.at(j);
      if(d.at(e.to) < d.at(e.from) + e.cost){
        d.at(e.to) = d.at(e.from) + e.cost;
        if(i == n-1 && e.to == n-1){
          cout << "inf" << endl;
          return 0;
        }
      }
    }
  }
  cout << d.at(n-1) << endl;
}