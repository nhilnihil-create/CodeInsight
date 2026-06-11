#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  vector<pair<int,int>> p;
  rep(i,0,N) {
    int A,B; cin >>A >>B;
    p.push_back(pair(A,B));
  }
  sort(p.rbegin(),p.rend());
  cout <<p[0].first+p[0].second <<endl;
  return 0;
}
