#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m,a[100],b[100],c[100];
  cin >> n >> m;
  for(int i = 0; i < m; i++)
    cin >> a[i] >> b[i];
  
  for(int i = 1; i <= n; i++)
    c[i] = 0;

  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < m; j++)
      if(i == a[j] || i == b[j]) c[i]++;
  
    cout << c[i] << endl;
  }
}