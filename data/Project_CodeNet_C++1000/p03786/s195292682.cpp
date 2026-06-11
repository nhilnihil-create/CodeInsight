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
  long long int n;
  cin>>n;
  vector<long long int> a(n);
  for(long long int i=0; i<n; i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());

  long long int all=0;
  long long int last=0;
  for(long long int i=0; i<n-1; i++){
    all+=a.at(i);
    if(2*all<a.at(i+1)){
      last=i+1;
    }
  }
  cout<<n-last<<endl;
}