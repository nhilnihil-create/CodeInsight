#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int n,m;
  cin>>n>>m;
  vector<int> A(m);
  vector<int> B(m);
  rep(i,m)cin>>A[i]>>B[i];
  vector<set<int>> G(n+1);
  rep(i,m) {
    G[A[i]].insert(B[i]);
    G[B[i]].insert(A[i]);
  }
  deque<int> dq;
  set<int> s;
  dq.push_back(1);
  s.insert(1);
  while(true) {
    // check
    bool f=true;
    for(auto v : G[dq.front()]) {
      if(s.find(v)==s.end()) {
        f=false;
      }
    }
    for(auto v : G[dq.back()]) {
      if(s.find(v)==s.end()) {
        f=false;
      }
    }
    if(f)
      break;
    for(auto v : G[dq.front()]) {
      if(s.find(v)==s.end()) {
        dq.push_front(v);
        s.insert(v);
        break;
      }
    }
    for(auto v : G[dq.back()]) {
      if(s.find(v)==s.end()) {
        dq.push_back(v);
        s.insert(v);
        break;
      }
    }
  }
  cout << dq.size() << endl;
  for(auto& x: dq) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
