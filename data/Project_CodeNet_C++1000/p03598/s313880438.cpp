#include<iostream>
using namespace std;
int main()
{
  int n,k;
  cin>>n;
  cin>>k;
  int sum=0;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(x<k){
      if(x>k-x){
        sum+=(k-x)*2;
      }
      else{
        sum+=x*2;
      }
    }
    else{
      if(x<x-k){
        sum+=x*2;
      }
      else{
        sum+=(x-k)*2;
      }
    }
  }
  cout<<sum;
}