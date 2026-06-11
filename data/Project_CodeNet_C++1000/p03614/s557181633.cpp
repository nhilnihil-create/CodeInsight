#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a[111111];
  vector<int>vec;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  int count=0;
  for(int i=1;i<=n-1;i++){
    if(a[i]==i){
      swap(a[i],a[i+1]);
      count++;
    }
  }
  if(a[n]==n){
    swap(a[n-1],a[n]);
    count++;
  }
  cout<<count<<endl;
  return(0);
}
