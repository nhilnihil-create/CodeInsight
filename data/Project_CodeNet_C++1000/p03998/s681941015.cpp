#include <bits/stdc++.h>
using namespace std;
vector<string> v(3);
int cnt = 0;

void game(int target) {
  if (v[target].empty()) {
    cout << char(target + 'A') << endl;
    return;
  }
  int old = target;
  target = v[target][0] - 'a';
  if (!v[target].empty()) {
    v[old].erase(0, 1);
  }
  game(target);
}

int main() {
  cin >> v[0] >> v[1] >> v[2];
  game(0);
  getchar();
}