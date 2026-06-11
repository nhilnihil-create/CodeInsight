#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int l, r;

  cin >> n;
  int count = 0;

  for(int i=0; i<n; i++){
    cin >> l >> r;
    count = count + (r - l)+ 1;
  }

  cout << count;
}