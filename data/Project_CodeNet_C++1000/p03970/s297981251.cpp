#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  string ex = "CODEFESTIVAL2016";

  int ans = 0;
  for (int i = 0; i < 16; i++)
    if (N.at(i) != ex.at(i)) ans++;
    
  cout << ans << endl;
}