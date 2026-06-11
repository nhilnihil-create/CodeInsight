#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >>n;
  long long kotae=1;
  vector<long long>a(n);
  for(long long i=0;i<n;i++)cin>>a[i];
  long long tmp=0;
  bool minus=false;
  bool plus=false;
  for(long long i=0;i<n-1;i++){
    //cout<<i<<" "<<a[i]-a[i+1]<<" "<<tmp<<endl;
    if(tmp==0){
      if(a[i]-a[i+1]<0){
        tmp=-1;
        minus=true;
        plus=false;
      }if(a[i]-a[i+1]>0){
        tmp=1;
        plus=true;
        minus=false;
      }
    }else if(a[i]-a[i+1]==0){
      if(tmp<0||minus==true){
        minus=true;
        plus=false;
        tmp=-1;
      }else if(tmp>0||plus==true){
        plus=true;
        minus=false;
        tmp=1;
      }
    }else if(a[i]-a[i+1]<0&&plus==true){
      kotae++;
      tmp=0;
      //minus=true;
      //plus=false;
    }else if(a[i]-a[i+1]>0&&minus==true){
      kotae++;
      tmp=0;
      //minus=false;
      //plus=true;
    }
  }
  cout<<kotae<<endl;
  return 0;
}