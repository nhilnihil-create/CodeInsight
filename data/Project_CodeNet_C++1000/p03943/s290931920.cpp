#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(3);
  for(int i=0; i<3; i++) {
    cin >> data[i];
  }
  sort(data.begin(), data.end());
  
  if(data[2] == data[0]+data[1]) cout << "Yes" << endl;
  else cout << "No" << endl;
}