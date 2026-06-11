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
int main(void){
  int n,m,k;
  cin>>n>>m>>k;
  
  bool ok=false;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=m; j++){
      int ans=0;
      ans+=i*m;
      ans+=j*n;
      ans-=i*j*2;
      if(ans==k){
        ok=true;
        break;
      }
    }
  }
  if(ok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}