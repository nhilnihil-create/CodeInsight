#include <bits/stdc++.h>
using namespace std;
long long X;
long long func(long long C){
  if(C==-1){
    return 0;
  }
  return C/X+1;
}
  
int main(){
  long long A,B;
  cin >> A >> B >> X;
  cout << func(B)-func(A-1) << endl;
}
  