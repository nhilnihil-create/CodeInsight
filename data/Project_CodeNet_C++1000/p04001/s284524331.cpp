#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int length = S.size();
  int64_t total = 0;  
  for (int i = 0; i < (1 << (length - 1)); i++) {
    bitset<9> op(i);
    int64_t sum = 0;
    string a;
    a += S.at(0);
    for (int j = 0; j < length - 1; j++) {
      if (op.test(j)) {
        sum += stoll(a);
        a ="";
        a += S.at(j + 1);
      }
      else {
        a += S.at(j + 1);
      }
      if (j == length - 2) {
        sum += stoll(a);
      }
    }
    if (length == 1) {
      sum += stoll(S);
    }
    total += sum;
  }
  cout << total << endl;  
}