#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,L[1100],r[1100],sum = 0;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> L[i] >> r[i];
    sum += (r[i]-L[i]+1);
  }
  cout << sum << endl;
}