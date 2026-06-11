#include<iostream>
using namespace std;

int main(){

  int a[4];
  int A,B;
  for(int i=0;i<4;i++)cin >> a[i];
  A=a[0]*a[1];
  B=a[2]*a[3];
  if(A>B){
    cout << A;
  }else if(A<=B){
  	cout << B;
  }
  return 0;
}