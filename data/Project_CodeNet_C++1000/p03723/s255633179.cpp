#include<bits/stdc++.h>
using namespace std;

int func(int A,int B,int C,int count){
    if(A%2==1 || B%2==1 || C%2==1){
      return count;
    }
  return func((B+C)/2,(C+A)/2,(A+B)/2,count+1);
}
    
int main(){
  int A,B,C;
  cin >> A >> B >> C;
  if(A==B && B==C && A%2==0){
    cout << -1 << endl;
  }
  else{
    cout << func(A,B,C,0) << endl;
  }
}