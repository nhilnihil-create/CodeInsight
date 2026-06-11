#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int oddCnt = 0;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    if(ai % 2 != 0) oddCnt++;
  }
  if(oddCnt % 2 == 0) cout << "YES";
  else cout << "NO";
}