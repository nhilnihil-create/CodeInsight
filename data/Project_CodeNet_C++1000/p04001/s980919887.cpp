#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}
 
int main() {
  string S;
  cin >> S;
  vector<int> A(S.size());
  int B = S.size();
  for (int i = 0; i < B; i++) {
    A.at(i) = ctoi(S.at(i));
  }
  int memo = B - 1;
  int64_t ans = 0;
  for (int tmp = 0; tmp < (1 << memo); tmp++) {
    bitset<10> s(tmp);
    int64_t m = 0;
    m += A.at(0);
    for (int i = 0; i < memo; i++) {
      if (s.test(i)) {
        ans += m;
        m = 0;
        m += A.at(i + 1);
      }
      else {
        m = m * 10 + A.at(i + 1);       
      }
      if (i == memo - 1) {
          ans += m;
      }
      
    }
  }
  if (B == 1) {
    ans += A.at(0);
  }
  cout << ans << endl;
}