#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
  }
  
  long long int diffmin = 2000000000000000;
  long long int snuke = 0;
  for(int i = 0; i < n - 1; i++) {
    snuke += a[i];
    long long int diff = sum - 2 * snuke;
    if(diff < 0) {
      diff *= -1;
    }
    diffmin = min(diff, diffmin);
  }

  cout << diffmin << endl;
}