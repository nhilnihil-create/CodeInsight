#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  if (count(S.begin(),S.end(),'W') == S.length() || count(S.begin(),S.end(),'B') == S.length()) {
    cout << 0;
  } else {
    int answer;
    string reversi;
    if (S[0] == 'W') {
      reversi.push_back('B');
      for (int i = S.find('B')+1; i < S.length(); i++) {
        if (S[i] != reversi.back()) {
          reversi.push_back(S[i]);
        }
      }
    } else {
      reversi.push_back('W');
      for (int i = S.find('W')+1; i < S.length(); i++) {
        if (S[i] != reversi.back()) {
          reversi.push_back(S[i]);
        }
      }
    }
    answer = reversi.length();
    reversi.clear();
    if (S.back() == 'B') {
      reversi.push_back('W');
      for (int i = S.rfind('W')-1; i+1; i--) {
        if (S[i] != reversi.back()) {
          reversi.push_back(S[i]);
        }
      }
    } else {
      reversi.push_back('B');
      for (int i = S.rfind('B')-1; i+1; i--) {
        if (S[i] != reversi.back()) {
          reversi.push_back(S[i]);
        }
      }
    }
    answer = min(answer,(int)reversi.length());
    cout << answer;
  }
}