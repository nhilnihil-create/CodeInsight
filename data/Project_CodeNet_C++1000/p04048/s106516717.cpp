#include<iostream>
using namespace std;
long N,X;
long g(long a,long b){return b?g(b,a%b):a;}
main()
{
  cin>>N>>X;
  cout<<3*(N-g(N,X))<<endl;
}