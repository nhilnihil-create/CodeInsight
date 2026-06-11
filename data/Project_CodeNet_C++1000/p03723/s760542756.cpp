#include<bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,C,num=0;
  cin >> A >> B >> C;
  while((A%2==0) && (B%2==0) && (C%2==0)){
    num++;
    long long x,y,z;
    x=A;
    y=B;
    z=C;
    A = (y+z)/2;
    B = (x+z)/2;
    C = (x+y)/2;
    if(A==B && B==C){
      num = -1;
      break;
    }
  }
  cout << num << endl;
  return 0;
}
  