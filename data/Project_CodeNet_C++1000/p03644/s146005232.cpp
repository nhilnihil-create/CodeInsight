#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(int i=a;i<b;++i)

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 10; ++i) {
    if (n < (1 << (i+1))) {
      cout << (1<<i) << endl;
      break;
    }
  }

  return 0;
}