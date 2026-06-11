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
  long long int k;
  cin>>k;
  long long int t;
  cin>>t;
  vector<long long int> a(t);
  for(long long int i=0; i<t; i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  while(a.size()>1){
    a.at(a.size()-1)-=a.at(0);
    a.erase(a.begin());
    sort(a.begin(),a.end());
  }
  if(a.at(0)==0){
    a.at(0)=1;
  }
  cout<<a.at(0)-1<<endl;
}