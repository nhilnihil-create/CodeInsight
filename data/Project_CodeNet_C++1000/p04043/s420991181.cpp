#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec(3);
  for(int i=0; i < 3; i++) {
    cin >> vec.at(i);
  }
  if (count(vec.begin(),vec.end(),5) == 2 && count(vec.begin(),vec.end(),7) == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}