#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m,t[200],p[200],x[200],sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> t[i];
    sum += t[i];
  }
  cin >> m;
  for(int i = 0; i < m; i++) 
    cin >> p[i] >> x[i];

  int z[200];
  for(int i = 0; i < m; i++) {
    z[i] = sum - t[p[i]-1] + x[i];
    cout << z[i] << endl;
  }
}