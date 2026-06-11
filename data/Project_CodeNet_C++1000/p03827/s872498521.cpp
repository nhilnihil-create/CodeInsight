#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  int count = 0;
  vector<int> x(n+1);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      x[0] = 0;
    }
    if (a[i] == 'I') {
      count++;
      x[i+1] = count;
    }
    else {
      count--;
      x[i+1] = count;
    }
  }
  sort(x.begin(), x.end());
  cout << x[n] << endl;
}
       