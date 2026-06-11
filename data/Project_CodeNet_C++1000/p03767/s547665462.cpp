#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,a[400000];
  cin >> n;
  for(int i = 0; i < 3*n; i++)
    cin >> a[i];
  
  sort(a,a+3*n,greater<int>());
  
  long sum = 0;
  for(int i = 1; i < 2*n; i++) {
    sum += a[i];
    i++;
  }
  cout << sum << endl;
}
