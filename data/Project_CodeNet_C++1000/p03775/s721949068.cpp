#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
#include<vector>
#include<math.h>
using namespace std;

long long int ketasuu(long long int a){
  long long int c=0;
  while(a!=0){
    a /=10;
    c++;
  }
  return c;
}

int main(){
  long long int n;
  cin>>n;
  long long int ans=n;
  for(long long int i=1;i<=sqrt(n);i++){
    if(n%i==0){
      ans=min(ans,max(ketasuu(i),ketasuu(n/i)));
    }
  }
  cout<<ans<<endl;
}