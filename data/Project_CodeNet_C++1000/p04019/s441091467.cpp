#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin>>S;
  map<char,int> m;
  for(auto x:S) m[x]++;
  bool ok = true;
  if(m['N']==0&&m['S']!=0) ok = false;
  if(m['S']==0&&m['N']!=0) ok = false;
  if(m['E']==0&&m['W']!=0) ok = false;
  if(m['W']==0&&m['E']!=0) ok = false;
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}