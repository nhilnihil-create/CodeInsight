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
  vector<long long int> a(n);
  int ki=0;
  int gu=0;
  for(long long int i=0; i<n; i++){
    cin>>a.at(i);
    if(a.at(i)%2==0){
      gu++;
    }else{
      ki++;
    }
  }

  long long int pre=pow(2,gu);
  long long int zero=0;
  long long int one=0;
  for(int i=0; i<=ki; i++){
    if(i%2==0){
      zero+=com(ki,i);
    }else{
      one+=com(ki,i);
    }
  }
  zero*=pre;
  one*=pre;
  
  if(p==0){
    cout<<zero<<endl;
  }else{
    cout<<one<<endl;
  }
}
