#include <bits/stdc++.h>
using namespace std;

int main() {
  int s,u;
  string t;
  cin >> s >> t >> u;
  if (t == "+") {
    cout << s + u << endl;
  }
  else if (t == "-") {
    cout << s - u << endl;
  }
}
