#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  string a,b;
  cin>>a>>b;
  string ans="EQUAL";
  if(a.size()>b.size()) ans="GREATER";
  else if(a.size()<b.size()) ans="LESS";
  else{
    for(int i=0;i<a.size();i++){
      if(a[i]-b[i]>0){
        ans="GREATER";
        break;
      }
      else if(a[i]-b[i]<0){
        ans="LESS";
        break;
      }
    }
  }
  cout<<ans<<endl;
}