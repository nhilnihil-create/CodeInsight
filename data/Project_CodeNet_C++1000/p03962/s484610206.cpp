#include <iostream>
using namespace std;
int main(){
 int A,B,C,ans = 3;
  cin >> A >> B >> C;
  if(A == B){
    if(B == C){
      cout << 1 << endl;
    }else{
      cout << 2 << endl;
    }
  }else{
    if(A == C || B == C){
      cout << 2 << endl;
    }else{
      cout << 3 << endl;
    }
  }
}