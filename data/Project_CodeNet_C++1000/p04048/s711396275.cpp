#include<iostream>
using namespace std;

long gcd(long x,long y){return y?gcd(y,x%y):x;}

int main(){
  long N,X;
  cin>>N>>X;
  cout <<3*(N-gcd(N,X));
}
