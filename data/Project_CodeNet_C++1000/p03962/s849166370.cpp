#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  if(A==B && B==C){
    cout << 1 << endl;
  }
  else if(A!=B && B!=C && C!=A){
    cout << 3 << endl;
  }
  else{
    cout << 2 << endl;
  }
} 