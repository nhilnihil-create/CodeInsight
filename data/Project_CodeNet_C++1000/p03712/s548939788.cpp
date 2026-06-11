#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,j;
  cin>>h>>w;
  vector<string> x(h);
  for(j=0;j<h;j++) cin>>x.at(j);
  for(j=0;j<w+2;j++) cout<<'#';
  cout<<endl;
  for(j=0;j<h;j++) cout<<'#'<<x.at(j)<<'#'<<endl;
  for(j=0;j<w+2;j++) cout<<'#';
  cout<<endl;
}