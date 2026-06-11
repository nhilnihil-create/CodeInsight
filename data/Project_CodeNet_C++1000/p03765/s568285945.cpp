#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  vector<int> v(S.size()+1, 0), w(T.size()+1, 0);
  REP(i, S.size()) {
    v[i+1] = v[i] + (S[i] == 'A' ? 1 : -1);
  }
  REP(i, T.size()) {
    w[i+1] = w[i] + (T[i] == 'A' ? 1 : -1);
  }
  int Q;
  cin >> Q;
  REP(_, Q) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int cS = v[B] - v[A-1], cT = w[D] - w[C-1];
    cout << ((cS - cT) % 3 == 0 ? "YES" : "NO") << endl;
  }
}