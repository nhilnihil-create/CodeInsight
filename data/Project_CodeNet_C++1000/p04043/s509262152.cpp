#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(3);
  int a=0, b=0;
  for(int i=0; i<3; i++) {
    cin >> data[i];
    if (data[i] == 5) a++;
    else if (data[i] == 7) b++;
  }
  if (a==2 && b==1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}