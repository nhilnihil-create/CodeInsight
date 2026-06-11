#include<bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z = 0; cin >> x >> y;
  vector<int> s = {4, 6, 9, 11}; bool j1 = false;
  for(int i = 0; i < 4; i++) {
    if(s[i] == x) z++;
    if(s[i] == y) z++;
  } if(z % 2 == 0) j1 = true;
  cout << (((x != 2 && y != 2) && j1) ? "Yes" : "No") << endl;
}
