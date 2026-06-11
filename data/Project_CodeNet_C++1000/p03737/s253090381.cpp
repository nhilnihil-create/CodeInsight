#include<bits/stdc++.h>
using namespace std;
int main(){
string s="";
  for(int i=0;i<3;i++){
  string x;
    cin>>x;
    char X=x.at(0);
    char y=char(X-32);
    s+=y;
  
  }cout<<s<<endl;
  
  
   return 0;
}