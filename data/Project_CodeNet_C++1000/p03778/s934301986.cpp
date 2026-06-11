#include<bits/stdc++.h>
using namespace std;
int main(){
  int W,a,b;
  cin>>W>>a>>b;
  vector<int>l(2);
  l.at(0)=a;
  l.at(1)=b;
  sort(l.begin(),l.end());
  cout<<max(0,l.at(1)-(l.at(0)+W))<<endl;
}