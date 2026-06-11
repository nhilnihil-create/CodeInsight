#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;

  if (N.size() <= 3)
    cout << "No" << endl;
  else if (N.substr(0, 4) == "YAKI")
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
