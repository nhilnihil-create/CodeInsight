#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,a[200000];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] % 2 == 1) cnt++;
  }
  if(cnt % 2 == 1) 
    cout << "NO" << endl;
  else
    cout << "YES" << endl;  
}
