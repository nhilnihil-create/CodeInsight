#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,c=1,mami=0;
  cin>>n>>t;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int ma=a[n-1],mi=a[n-1];
  for(int i=n-2;i>=0;i--){
    if(a[i]>ma){
      ma=a[i];
      mi=a[i];
    }else if(a[i]<mi){
      mi=a[i];
      if(ma-mi==mami) c++;
      else if(ma-mi>mami){
        mami=ma-mi;
        c=1;
      }
    }
  }
  cout<<c<<endl;
}
      
  