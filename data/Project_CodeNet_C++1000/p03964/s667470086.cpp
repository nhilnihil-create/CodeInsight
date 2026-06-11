#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<pair<double,double>> hoge(n);
  for(int i=0; i<n; i++){
    cin>>hoge.at(i).first>>hoge.at(i).second;
  }

  long long int a=hoge.at(0).first,b=hoge.at(0).second;
  for(int i=1; i<n; i++){
    long long int x,y;
    x=hoge.at(i).first;
    y=hoge.at(i).second;
    long long int prex,prey;
    prex=a/x;
    if(a%x!=0){
      prex++;
    }
    prey=b/y;
    if(b%y!=0){
      prey++;
    }
    long long int m=max(prex,prey);
    a=m*x;
    b=m*y;
  }
  cout<<a+b<<endl;
}