#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(s[i]==s[j]){
        ans++;
        break;
      }
    }
  }
  if(ans){
    cout<<"no"<<endl;
  }
  else{
    cout<<"yes"<<endl;
  }
}