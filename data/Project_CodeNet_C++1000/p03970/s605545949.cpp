#include<bits/stdc++.h>
using namespace std;
signed main(){
  string a; 
  string b="CODEFESTIVAL2016";
  int c=0;
  cin>>a;
  for(int i=0;i<a.size();i++){
    if(a[i]!=b[i]) c++;
  }
  cout<<c<<"\n";
}
