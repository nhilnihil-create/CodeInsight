#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,ans=0;
  long long int a[110000];
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++){
    while(i+1<n && a[i]==a[i+1]) i++;
    if(a[i]<a[i+1]){
      while( i+1<n && a[i]<=a[i+1]) i++;
    }
    else if(a[i]>a[i+1]){
      while(i+1<n && a[i]>=a[i+1]) i++;
    }
    ans++;
  }
  cout<<ans;
}
