#include<iostream>
using namespace std;

long long int gcd(long long int a,long long int b){
  if(a%b==0) return(b);
  else return(gcd(b,a%b));
}

int main(){
  long long int N,K;
  cin>>N>>K;
  cout<<((N/gcd(N,K))*3-3)*gcd(N,K)<<endl;
}