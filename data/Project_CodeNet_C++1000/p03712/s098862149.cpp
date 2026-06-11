#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<string,string>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H,W;
  cin>>H>>W;
  vector<string> v(H);
  rep(i,H) cin>>v[i];
  rep(i,W+2) cout<<'#';
  cout<<endl;
  rep(i,H){
    cout<<'#';
    cout<<v[i];
    cout<<'#'<<endl;
  }
  rep(i,W+2) cout<<'#';
  cout<<endl;
}