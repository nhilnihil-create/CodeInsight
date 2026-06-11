#include<bits/stdc++.h>
using namespace std;
long long a,b,x;
long long f(long long n){
  if(n>=0)return n/x+1;
  else return 0;
}
int main(){
  std::cin>>a>>b>>x;
  std::cout<<f(b)-f(a-1);
  return 0;
}