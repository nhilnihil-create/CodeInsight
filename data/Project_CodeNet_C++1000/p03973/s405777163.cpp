#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) {
    cin>>a[i];
  }
  long long cnt = a[0] - 1;;
  int p = 2;
  for (int i=1; i<n; i++) {
    if (p > a[i]) {
    } else if (p == a[i]) {
      ++p;
    } else {
      cnt += (a[i] - 1) / p;
    }
  }
  cout<<cnt<<endl;
}