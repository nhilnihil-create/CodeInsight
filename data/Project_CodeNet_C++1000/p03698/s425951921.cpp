#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  vector<int> alphabet(26, 0);

  for (int i = 0; i < S.length(); i++) {
    int index = S[i] - 1;
    alphabet[index]++;

    if (alphabet[index] > 1) {
      cout << "no" << endl;
      return 0;
    }
  }

  cout << "yes" << endl;
}
