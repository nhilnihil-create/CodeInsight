#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int oddc = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    oddc += x % 2;
  }

  if (oddc % 2 == 1) {
    cout << "NO" << endl;
  } else{
    cout << "YES" << endl;
  }
}
