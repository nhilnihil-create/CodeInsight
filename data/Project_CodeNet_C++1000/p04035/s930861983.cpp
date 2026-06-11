#include<bits/stdc++.h>
using namespace std;

int main(){
  int i,j,cnt=0;
  int n,l;
  cin>>n>>l;
  int a[n];
  for(i=0;i<n;i++)cin>>a[i];
  bool flg=1;
  for(i=0;i<n-1;i++){
    if(a[i]+a[i+1]>=l){
      flg=0;
      cnt=i+1;
      break;
    }
  }
  if(flg){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  for(i=1;i<cnt;i++){
    cout<<i<<endl;
  }
  for(i=n-1;i>cnt;i--){
    cout<<i<<endl;
  }
  cout<<cnt<<endl;
}