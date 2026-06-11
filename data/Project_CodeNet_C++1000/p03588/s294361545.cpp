#include <iostream>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  long long a = 0, b = 0;
  long long maxa = 0, minb = 1e10; 
  for (int i=0; i<n; i++) {
    cin >> a >> b;
    if (a > maxa) {
      maxa = a;
      minb = b;
    }
  }
  cout << maxa + minb << endl;
  return 0;
}
