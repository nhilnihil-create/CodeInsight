#include<iostream>
using namespace std;

int main(){
  int N,K,X,Y;
  cin>>N>>K>>X>>Y;
  cout<<(N<=K?X*N:X*K+Y*(N-K))<<endl;
  return 0;
}
