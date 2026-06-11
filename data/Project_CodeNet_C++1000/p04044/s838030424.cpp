#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S.at(i);
  
  sort(S.begin(), S.end());
  string str = "";
  for (auto s: S) {
    str += s;
  }
  
  cout << str << endl;
}
