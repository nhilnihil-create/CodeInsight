#include <bits/stdc++.h>
using namespace std;
int main () {
 char a, b;
 cin >> a >> b ;
  
 bool A = (a == 'H');
 bool B = b == 'H';
  
  if ((A&&B) || (!A&&!B) ){
    cout << 'H' << endl;
  }
  else{
    cout << 'D' << endl;
  }
}