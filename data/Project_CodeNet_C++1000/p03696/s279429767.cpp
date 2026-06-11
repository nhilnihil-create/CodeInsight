#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  string S;
  cin >> N >> S;
  int k = 0;
  REP(i, S.size()) {
    if (S[i] == ')') {
      if (0 == k) {
        S.insert(S.begin(), '(');
        k++;
        i++;
      }
      k--;

    } else {
      k++;
    }
  }
  k = 0;
  for (int i = S.size()-1; i >= 0; i--) {
    if (S[i] == '(') {
      if (0 == k) {
        S.push_back(')');
        k++;
      }
      k--;
    } else {
      k++;
    }
  }
  cout << S << endl;
}