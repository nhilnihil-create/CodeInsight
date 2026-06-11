#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) {
    cin >> A.at(i);
    --A.at(i);
  }
  set<int> found;
  int current = 0;
  found.insert(current);
  int count = 1;
  REP(i, N){
    int next = A.at(current);
    if(next == 1){
      cout << count << endl;
      return 0;
    }

    if(found.find(next) != found.end()){
      break;
    }
    found.insert(next);
    current = next;
    ++count;
  }

  cout << -1 << endl;

  return 0;
}
