#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
long long int com(long int n,long int r){
  long long int re=1;
  long long int pre=1;
  for(long long int i=0; i<r; i++){
    re*=n-i;
    if(re%(r-i)==0){
      re/=r-i;
    }else{
      pre*=r-i;
    }
    if(re%pre==0){
      re/=pre;
      pre=1;
    }
  }
  re/=pre;
  return re;
}
int main(void){
  int n,p;
  cin>>n>>p;
  int gu=0;
  int ki=0;
  for(int i=0; i<n; i++){
    int pre;
    cin>>pre;
    if(pre%2==0){
      gu++;
    }else{
      ki++;
    }
  }

  long long int ans=pow(2,n-1);
  if(ki==0){
    if(p==1){
      ans=0;
    }else{
      ans=pow(2,n);
    }
  }
  cout<<ans<<endl;
}