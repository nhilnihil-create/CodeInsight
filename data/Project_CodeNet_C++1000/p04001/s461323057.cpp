#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int64_t result = 0, n = S.size();
  for (int i = 0; i < 1 << n - 1; i++) {
    int64_t index = 0, count = 1, add_num;
    bitset<9> plus(i);
    for (int j = n - 2; -1 < j; j--) {
      if (plus.test(j) & 1) {
        add_num = stol(S.substr(index, count));
        index = index + count;
        result += add_num;
        count = 1;
      } else count++;
    }
    add_num = stol(S.substr(index, n));
    result += add_num;
  }
  cout << result << endl;
}
