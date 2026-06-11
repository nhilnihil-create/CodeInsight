#include <bits/stdc++.h>
using namespace std;

int main(){
  char A,B;
  cin >> A >> B;
  if(A == 'H'){
    if(B == 'H'){
      cout << 'H' << endl;
    }
    else{
      cout << 'D' << endl;
    }
  }
  else{
    if(B == 'H'){
      cout << 'D' << endl;
    }
    else{
      cout << 'H' << endl;
    }
  }
}