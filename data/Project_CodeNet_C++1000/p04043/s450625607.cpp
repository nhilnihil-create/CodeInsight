#include<iostream>
using namespace std;
int main(){
  int A,B,C;
  cin >> A >> B >> C;
  int n5=0;
  int n7=0;
  if(A==5) n5++;
  if(B==5) n5++;
  if(C==5) n5++;
  if(A==7) n7++;
  if(B==7) n7++;
  if(C==7) n7++;
  if(n5==2 && n7==1) cout << "YES";
  else cout << "NO";
  
  return 0;
}