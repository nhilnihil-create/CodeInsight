#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  for(int i=0;i<n;i++){
    if(ans>=n-i){
      break;
    }
    int z;
    if(s[i]=='A'){
      for(int j=i+1;j<n;j++){
        z=0;
        if(s[j]=='Z'){
          z=j-i+1;
          if(ans<z){
            ans=z;
          }
        }
      }
      i+=z;
    }
  }
  cout<<ans<<endl;
}