#include<bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n,m; cin >> n >> m;
  vector<vi> to(n);
  rep(i,m){
    int a,b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  for(auto i : to[0]){
    for(auto j : to[i]){
      if(j == n-1){
        cout << "POSSIBLE\n";
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE";
  cout << "\n";
  return 0;
}
