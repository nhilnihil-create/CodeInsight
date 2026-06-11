#include<iostream>
using namespace std;
int main(){
  long long int a,b,x;
  cin >>a >> b >>x ;
  long long int flag = 0;
  if (a%x==0)flag = 1;
  a = a - (a % x);
  b  = b - (b % x);
  cout << (b - a) / x + flag << endl;
  return 0;
}