#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  string s;
  cin>>s;
  string C="CODEFESTIVAL2016";
  for(i=0;i<C.size();i++){
    if(s[i]!=C[i])cnt++;
  }
  cout<<cnt;
}