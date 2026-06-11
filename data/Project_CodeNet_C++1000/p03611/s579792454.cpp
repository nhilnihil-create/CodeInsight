#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;
  
  vector<int> a(n),b(100000);
  for ( int i = 0; i < n; i++){
    cin >> a[i];
    if ( a[i] == 0 ){
      b[0]++;
      b[1]++;
      continue;
    }else if ( a[i] == 99999 ){
      b[99999]++;
      b[99998]++;
    }else{
      b[a[i]]++;
      b[a[i]+1]++;
      b[a[i]-1]++;
    }   
  }
  
  int saidai;
  for ( int i = 0; i < 100000; i++){
    saidai = max(saidai,b[i]);
  }
  
  cout << saidai << endl; 
  
}