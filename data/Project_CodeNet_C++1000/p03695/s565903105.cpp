// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

typedef pair<int, int> P;

vector<int> B { 399, 799, 1199, 1599, 1999, 2399, 2799, 3199 };

int main() {
  int n; cin >> n;
  vector<int> A(n);
  loop(i,0,n) cin >> A[i];
  set<int> S;
  int cnt = 0;
  loop(i,0,n) {
    int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    if (idx == B.size()) {
      cnt++;
      continue;
    }
    S.insert(idx);
  }
  cout << max(1, (int)S.size()) << " " << cnt + S.size() << endl;
  return 0;
}
