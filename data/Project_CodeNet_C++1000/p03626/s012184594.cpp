#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s,t;
  cin>>n>>s>>t;
  vector<bool> d;
  d.push_back(1);
  int p=0;
  for(int i=1;i<n;i++){
    if(s.at(i)==s.at(i-1))
      d.at(p)=0;
    else{
      d.push_back(1);
      p++;
    }
  }
  int64_t c=(d.at(0)?3:6);
  for(int i=1;i<d.size();i++){
    if(d.at(i-1)&&d.at(i))
      c*=2;
    if(d.at(i-1)&&!d.at(i))
      c*=2;
    if(!d.at(i-1)&&d.at(i))
      c*=1;
    if(!d.at(i-1)&&!d.at(i))
      c*=3;
    c%=1000000007;
  }
  cout<<c<<endl;
}