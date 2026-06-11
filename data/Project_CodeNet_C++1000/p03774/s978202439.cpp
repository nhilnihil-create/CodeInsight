#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m,a[100],b[100],c[100],d[100];
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  for(int i = 0; i < m; i++)
    cin >> c[i] >> d[i];
  
  for(int i = 0; i < n; i++) {
    int mi = 2000000000;
    int t;
    for(int j = 0; j < m; j++) {
      if(mi > (abs(a[i]-c[j])+abs(b[i]-d[j]))) {
        mi = (abs(a[i]-c[j])+abs(b[i]-d[j]));
        t = j+1;
      }
    }
    cout << t << endl;
  }
}
