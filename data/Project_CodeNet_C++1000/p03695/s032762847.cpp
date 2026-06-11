#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  int a,saishou = 0;
  vector<int> c(9,0);
  
  for ( int i = 0; i < n; i++){
    cin >> a;
    if ( a < 400 ){
      c[0] = 1;
    }else if ( a >= 400 && a < 800 ){
      c[1] = 1;
    }else if ( a >= 800 && a < 1200 ){
      c[2] = 1;
    }else if ( a >= 1200 && a < 1600 ){
      c[3] = 1;
    }else if ( a >= 1600 && a < 2000 ){
      c[4] = 1;
    }else if ( a >= 2000 && a < 2400 ){
      c[5] = 1;
    }else if ( a >= 2400 && a < 2800 ){
      c[6] = 1;
    }else if ( a >= 2800 && a < 3200 ){
      c[7] = 1;
    }else{
      c[8]++;
    }
  }
  
  for ( int i = 0; i < 8; i++){
    saishou += c[i];
  }
  
  if ( saishou == 0 ){
    cout << 1 << ' ' << c[8] << endl;
  }else{
    cout << saishou << ' ' << saishou + c[8] << endl;
  }
  
}
