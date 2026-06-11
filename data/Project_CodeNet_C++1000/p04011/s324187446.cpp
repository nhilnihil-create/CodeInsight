#include<iostream>
using namespace std;
int main()
{
  int n,k,x,y;
  cin>>n;
  cin>>k;
  cin>>x;
  cin>>y;
  int z;
  z=n-k;
  if(n>k){
  cout<<(k*x)+(z*y);
  }
  else{
    cout<<n*x;
  }
}