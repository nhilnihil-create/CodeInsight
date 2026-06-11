#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, C;
  string B;

  cin >> A >> B >> C;
  if (B == "+") {
    cout << A + C << endl;
  } else {
    cout << A - C << endl;
  }
}