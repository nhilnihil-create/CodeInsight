#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
     cin>>a[i];
  }
  map<int,int>k;
  for(int i=0;i<N;i++){
     if(a[i]>=1&&a[i]<=399){k[1]++;}
     if(a[i]>=400&&a[i]<=799){k[2]++;}
     if(a[i]>=800&&a[i]<=1199){k[3]++;}
     if(a[i]>=1200&&a[i]<=1599){k[4]++;}
     if(a[i]>=1600&&a[i]<=1999){k[5]++;}
     if(a[i]>=2000&&a[i]<=2399){k[6]++;}
     if(a[i]>=2400&&a[i]<=2799){k[7]++;}
     if(a[i]>=2800&&a[i]<=3199){k[8]++;}
     if(a[i]>=3200){k[9]++;}
  }
  int count=0;int count2=0;
  for(auto a:k){
   if(a.first<=8&&a.second>=1){count++;}
   if(a.first==9&&a.second>=1){count2=a.second;}
  }
  if(count>0){cout<<count<<" "<<count+count2<<endl;}
  else {cout<<1<<" "<<count2<<endl;}
return 0;}