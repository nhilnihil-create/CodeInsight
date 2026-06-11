#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int maxt = 0;
  int maxi = 1;
  for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = i; j % 2 == 0; j /= 2) {
      t++;
    }
    if (maxt < t) {
      maxt = t;
      maxi = i;
    }
  }
  cout << maxi << endl;
  return 0;
}
