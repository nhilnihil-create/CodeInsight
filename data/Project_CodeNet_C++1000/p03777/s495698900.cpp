#include<bits/stdc++.h>
using namespace std;
int main(){
  char a,b;
  cin >> a ;
  cin >> b ;
  if (a == 'H' ){
    if (b == 'H') cout << "H" << endl;
    else if (b == 'D') cout << "D" << endl;
  }
  else if (a == 'D'){
    if (b == 'H') cout << "D" << endl;
    else if (b == 'D') cout << "H" << endl;
  }
  return 0;
}

