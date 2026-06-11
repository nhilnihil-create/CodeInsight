#include <bits/stdc++.h>
using namespace std;
int main() {
  int abc[3];
  cin >> abc[0] >> abc[1] >> abc[2];
  sort(abc,abc+3);
  if (abc[0]+abc[1] == abc[2]) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}