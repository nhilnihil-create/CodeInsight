#include <bits/stdc++.h>
using namespace std;

int main() {
  string stg;
  cin >> stg;

  replace(stg.begin(), stg.end(), ',' ,' ');
  cout << stg << endl;
}