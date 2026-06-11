# include <bits/stdc++.h>
using namespace std;

int main() {
  int rows;
  int columns;
  string s;

  cin >> rows;
  cin >> columns;

  getline(cin, s); // 1行目の最後まで読んでおく

  vector<string> strs(rows);
  for (int i = 0; i < rows; i++) {
    getline(cin, strs[i]);
  }
  for (int j = 0; j < columns + 2; j++) {
      cout << '#';
  }
  cout << endl;
  for (string s: strs) {
    cout << '#' << s << '#' << endl;
  }
  for (int k = 0; k < columns + 2; k++) {
      cout << '#';
  }
}