#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  for (int i = 0; i < k+2; i++) {
    cout << "#";
  }
  cout << endl;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    cout << "#" << s << "#" << endl;
  }
  for (int i = 0; i < k+2; i++) {
    cout << "#";
  }
}
