#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;

  int n = s.size();
  int answer = n;
  for (char c = 'a'; c <= 'z'; ++c) {
    int seq = 0;
    int max_seq = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == c) {
        max_seq = max(max_seq, seq);
        seq = 0;
      } else {
        ++seq;
      }
    }
    max_seq = max(max_seq, seq);
    answer = min(answer, max_seq);
  }
  
  cout << answer << endl;
  return 0;
}
