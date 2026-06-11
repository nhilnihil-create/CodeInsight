#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  long n,a[200000];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a,a+n);

  int cnt = 0;
  for(long i = 0; i < n; i++) {
    if(i+1 < n & a[i] == a[i+1]) i++;
    else cnt++; 
  }

  cout << cnt << endl; 
}