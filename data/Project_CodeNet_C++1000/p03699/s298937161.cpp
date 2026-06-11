#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  int goukei = 0;
  vector<int> a(n);
  for ( int i = 0; i < n; i++){
    cin >> a[i];
    goukei += a[i];
  }
  
  if ( goukei % 10 != 0 ){
    cout << goukei << endl;
    return 0;
  }
  
  sort(a.begin(),a.end());
  
  for ( int i = 0; i < n; i++){
    if ( a[i] % 10 != 0 ){
      cout << goukei - a[i] << endl;
      return 0;
    }
  }
  
  cout << 0 << endl;
  
}