#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long x;
  cin >> x;

  if(x % 11 <= 6 && x % 11 != 0) {
    cout << (x+(11-1))/11*2 - 1 << endl;
  }
  else {
    cout << (x+(11-1))/11*2  << endl;
  }

    return 0;
}
