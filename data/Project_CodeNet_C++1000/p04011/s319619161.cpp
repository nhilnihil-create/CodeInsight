#include<iostream>
using namespace std;

int main(){
 int n,k,x,y;
  cin>>n>>k>>x>>y;
  
  int fee=0;
  if(n<=k){
    fee=x*n;
  }else{
    fee=x*k;
    fee+=y*(n-k);
  }
  
  cout<<fee<<endl;
  return 0;
}