#include <bits/stdc++.h>
using namespace std;

bool isodd(int A, int B, int C){
	if(A % 2 ==0 && B % 2 ==0 && C % 2 ==0){
      return true;
    }else{
      return false;
    }
}
 
int main() {
 
  int A,B,C;
  cin >> A >> B >> C;
  
  int count = 0;
  bool ff = false;
  
  while( isodd(A,B,C) ){
    
    if(A == B && B == C){
     ff = true;
     break;
    }
    
    int h_A,h_B,h_C;
    h_A = A/2;
    h_B = B/2;
    h_C = C/2;
    A = h_B + h_C;
    B = h_A + h_C;
    C = h_A + h_B;
    
    count++;
  }
  
  if(ff == false){
      cout << count << endl;
  }else{
      cout << "-1" << endl;
  }
 
}