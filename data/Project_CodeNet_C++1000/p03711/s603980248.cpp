#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int x,y;
  cin >> x >> y;
  
  int hantei1 = 0,hantei2 = 0;
  
  vector<int> a={1,3,5,7,8,10,12},b={4,6,9,11};
  
  for ( int i = 0; i < 7; i++){
    if ( x == a.at(i) ){
      hantei1 += 1;
    }
    if ( y == a.at(i) ){
      hantei1 += 1;
    }
  }
  
  for ( int i = 0; i < 4; i++){
    if ( x == b.at(i) ){
      hantei2 += 1;
    }
    if ( y == b.at(i) ){
      hantei2 += 1;
    }
  }
  
  if ( hantei1 == 2 || hantei2 == 2 ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
    
}

