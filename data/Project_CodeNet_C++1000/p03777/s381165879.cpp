#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char a ,b,c;
  cin  >> a >> b ;
  if ( a == 'H'){
    c = b;
  }
  if ( a == 'D'){
    if ( b == 'H'){
    c = 'D';
    }else c='H';
  }
  cout << c << endl; 
}