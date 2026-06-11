#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  

int main(void){
  long long res=0;
  long long bus_t,bus_c;
  long long i,j;
  long long n,c,k;
  
  cin>>n>>c>>k;
  long t[n];
  
  for(i=0;i<n;i++){
    cin>>t[i];
  }
  sort(t,t+n);
  /*
  for(i=0;i<n;i++){
    cout<<t[i]<<endl;
  }*/
  
  
  bus_t=t[0];
  bus_c=1;
  res=1;
  for(i=1;i<n;i++){
    if(t[i]<=(bus_t+k)){
      if(bus_c==c){
        bus_t=t[i];
        bus_c=1;
        res++;
      }
      else{
        bus_c++;
      }
    }
    else{
      bus_t=t[i];
      bus_c=1;
      res++;
    }
  }
  

  
  cout<<res<<endl;
  return 0;
}