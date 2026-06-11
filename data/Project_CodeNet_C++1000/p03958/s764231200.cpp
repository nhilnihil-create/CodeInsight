#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int K, T;
  cin >> K >> T;
  vector<int> a(T);
  for (int i=0; i<T; i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  cout << max((2*a[T-1]-K-1),0) << endl;
}