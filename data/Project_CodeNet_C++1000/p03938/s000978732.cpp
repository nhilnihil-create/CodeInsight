#include<bits/stdc++.h>
using namespace std;
int a[20009],b[20009];

int main(){
  int n;
  int p[20009];
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }

  for(int i=1;i<=n;i++){
    a[p[i]]+=i;
    b[p[i]]+=i;
  }
  for(int i=1;i<=n;i++){
    a[i]+=a[i-1];
  }
  for(int i=n;i>=1;i--){
    b[i]+=b[i+1];
  }

  for(int i=1;i<=n;i++){
    cout<<a[i]+i;
    if(i==n)cout<<endl;
    else cout<<' ';
  }
  for(int i=1;i<=n;i++){
    cout<<b[i]+n-i+1;
    if(i==n)cout<<endl;
    else cout<<' ';
  }

  return(0);
}
