#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a=0,b,c,d=2,e=1,f=0,g=0;
  string s,u="CODEFESTIVAL2016";
  cin >>s;
  for(int n=0;n<16;n++){
    if(s[n]!=u[n]) a++;
  }
  cout<<a<<'\n';
  return (0);
}
