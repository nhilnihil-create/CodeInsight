#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A = {0,1,3,1,2,1,2,1,1,2,1,2,1};
  int x,y; cin >> x >> y;
  if(A.at(x) == A.at(y))
    cout << "Yes";
  else cout << "No";
}