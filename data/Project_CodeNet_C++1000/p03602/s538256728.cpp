#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long length = 0;
  int a[310][310];
  bool ans = true;
  
  cin >> n;
  for (int i = 0;i < n;++i) for (int j = 0;j < n;++j) cin >> a[i][j];
  
  for (int i = 0;i < n-1;++i) {
    for (int j = i+1;j < n;++j) {
      bool temp = true;
      for (int k = 0;k < n;++k) {
	if (a[i][j] > a[i][k]+a[k][j]) ans = false;
	if (a[i][j] == a[i][k]+a[k][j] && k != i && k != j) temp = false;
      }
      if (temp) length += a[i][j];
    }
  }
  
  cout << (ans ? length : -1) << endl;
  return 0;
}