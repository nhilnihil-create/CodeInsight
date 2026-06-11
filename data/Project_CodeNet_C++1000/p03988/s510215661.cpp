#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int a[n];
  int cnt[101];fill(cnt,cnt+101,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  sort(a,a+n);
  bool ok=true;
  if(cnt[a[n-1]]==1){
    ok=false;
  }
  else{
    if(a[n-1]%2==0){
      for(int i=1;i<a[n-1];i++){
        if(i<a[n-1]/2){
          if(cnt[i]>0)ok=false;
        }
        else if(i==a[n-1]/2){
          if(cnt[i]!=1)ok=false;
        }
        else{
          if(cnt[i]<=1)ok=false;
        }
      }
    }
    else{
      for(int i=1;i<a[n-1];i++){
        if(i<=a[n-1]/2){
          if(cnt[i]>0)ok=false;
        }
        else if(i==a[n-1]/2+1){
          if(cnt[i]!=2)ok=false;
        }
        else{
          if(cnt[i]<=1)ok=false;
        }
      }
    }
  }
  if(ok)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}