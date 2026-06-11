#include <bits/stdc++.h>
using namespace std;

// アルファベットを数値に変換 → 'c' - 'a' = 2
// 数値をアルファベットに変換 → (char)(2 + 'a') = 'c'

int main() {
  string S;
  cin >> S;

  bool alphabets[26];
  fill(alphabets, alphabets + 26, false);
  for (int i = 0; S[i] != '\0'; i++) alphabets[S[i] - 'a'] = true;

  for (int i = 0; i < 26; i++) {
    if (alphabets[i] == false) {
      cout << (char)(i + 'a') << endl;
      return 0;
    }
  }

  cout << "None" << endl;
  return 0;
}