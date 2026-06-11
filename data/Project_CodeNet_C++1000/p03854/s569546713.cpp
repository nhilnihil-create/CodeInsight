#include <iostream>

using namespace std;

string S;

bool match(int i, string t) {
  if (i + t.size() > S.size()) return false;
  for (int j = 0; j < t.size(); ++j) {
    if (S[i + j] != t[j]) return false;
  }
  return true;
}

bool dfs(int i) {
  return S.size() == i
         || match(i, "dreamer") && dfs(i + 7)
         || match(i, "eraser") && dfs(i + 6)
         || (match(i, "dream") || match(i, "erase")) && dfs(i + 5);
}

int main() {
  cin >> S;

  cout << (dfs(0) ? "YES" : "NO") << endl;
}
