#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

int N, M;
int X[100010];
int mod[100010];
int same[100010];
int same_mod[100010];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; i++) {
    cin >> X[i];
  }
  fill(mod, mod+100010, 0);
  fill(same, same+100010, 0);
  fill(same_mod, same_mod, 0);
  for (auto i = 0; i < N; i++) {
    mod[X[i]%M]++;
    same[X[i]]++;
  }
  for (auto i = 0; i < 100010; i++) {
    same_mod[i%M] += (same[i]/2)*2;
  }
  int ans = 0;
  for (auto i = 1; i <= M/2; i++) {
    if (M%2 == 0 && i == M/2) continue;
    int t = min(mod[i], mod[M-i]);
    // cerr << i << " " << t << endl;
    ans += t;
    mod[i] -= t;
    mod[M-i] -= t;
  }
  ans += mod[0]/2;
  mod[0] %= 2;
  // cerr << ans << endl;
  if (M%2 == 0) {
    ans += mod[M/2]/2;
    mod[M/2] %= 2;
    // cerr << ans << endl;
  }
  for (auto i = 0; i < M; i++) {
    // cerr << "mod[" << i << "] = " << mod[i] << ", ";
    // cerr << "same_mod[" << i << "] = " << same_mod[i] << endl;
    ans += min(mod[i], same_mod[i])/2;
  }
  cout << ans << endl;
}
