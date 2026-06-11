#include<iostream>
#define M 1000000007L
long n,m;
long f(long x) {
  return x-1?x*f(x-1)%M:1;
}
main() {
  std::cin>>n>>m;
  std::cout<<f(n)*f(m)*((abs(n-m)<2)+(n==m))%M;
}
