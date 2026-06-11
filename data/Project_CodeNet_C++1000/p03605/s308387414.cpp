#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string ans="No";
  cin >> N;
  if(N/10==9) ans="Yes";
  if(N%10==9) ans="Yes";
  cout << ans << endl;
}