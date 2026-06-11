#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,last=0,cnt=0;
  int a[100009];
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(i==a[i])cnt++;
  }
  for(int i=1;i<=n-1;i++){
    if(a[i]==i&&a[i+1]==i+1&&last==0){
      cnt--;
      last=1;
    }
    else last=0;
  }
  cout<<cnt<<endl;
  return(0);
}
