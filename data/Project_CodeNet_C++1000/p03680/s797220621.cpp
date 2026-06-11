#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  vector<int> btn(n);
  for(int i = 0; i < n; ++i) {
    cin >> btn.at(i);
  }

  int num = 0;
  for(int i = 1; i < n; ++i) {
    if(btn.at(num) == 2) {
      cout << i << "\n"; return 0;
    }
    num = btn.at(num) - 1;
  }
  cout << -1 << "\n";
}