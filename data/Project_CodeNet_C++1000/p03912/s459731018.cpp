#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int solve(const vector<int> &idx1, const vector<int> &idx2, const vector<int> &X) {
  vector<int> Y1, Y2;
  for(int e: idx1) Y1.push_back(X[e]);
  for(int e: idx2) Y2.push_back(X[e]);

  int residue = 0;
  sort(ALL(Y2));
  vector<int> unY2 = Y2;
  unY2.erase(unique(ALL(unY2)), unY2.end());
  int m = unY2.size();
  REP(i,m) {
    auto itr = equal_range(ALL(Y2), unY2[i]);
    residue += ((itr.second - itr.first) / 2) * 2;
  }
  int res = Y1.size() + min(residue, (int)Y2.size() - (int)Y1.size()) / 2;
  return res;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> X(N);
  REP(i,N) cin >> X[i];
  vector<vector<int>> mod(M);
  REP(i,N) mod[X[i] % M].push_back(i);

  int res = mod[0].size() / 2;
  for(int i = 1; i <= M / 2; ++i) {
    if(2 * i == M) res += mod[M / 2].size() / 2;
    else {
      if(mod[i].size() < mod[M - i].size()) {
        res += solve(mod[i], mod[M - i], X);
        //cout << i << " " << M - i << ": " << solve(mod[i], mod[M- i], X) << endl;
      }else{
        res += solve(mod[M - i], mod[i], X);
        //cout << i << " " << M - i << ": " << solve(mod[i], mod[M- i], X) << endl;
      }
    }
  }
  cout << res << endl;
  return 0;
}

