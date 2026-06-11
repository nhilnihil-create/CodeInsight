#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i;
  cin>>n;
  vector<int> a(n);
  for(i=0;i<n;i++) cin>>a.at(i);
  if(n%2==1){
    for(i=n-1;i>=0;i-=2){
      cout<<a.at(i);
      if(i>0) cout<<' ';
    }
    for(i=1;i<n;i+=2) cout<<' '<<a.at(i);
  }
  else if(n%2==0){
    for(i=n-1;i>=0;i-=2){
      cout<<a.at(i);
      if(i>1) cout<<' ';
    }
    for(i=0;i<n;i+=2) cout<<' '<<a.at(i);
  }
  cout<<endl;
}