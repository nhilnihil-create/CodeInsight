#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vec(3);
  for(int i = 0; i < 3; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  if(vec[0] = 5 && vec[1] == 5 && vec[2] == 7) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}
