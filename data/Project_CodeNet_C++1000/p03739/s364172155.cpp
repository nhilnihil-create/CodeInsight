#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin >> n;
  int d[n];
  
  for(int i=0;i<n;i++) cin >> d[i];
int64_t sume=0;
int64_t counte=0;  
for(int i=0;i<n;i++){
  sume+=d[i];
  if(i%2==0){
    if(sume<=0){
      counte+=1-sume;
      sume=1;    
    }
  }
  else{
    if(sume>=0){
      counte+=sume+1;
      sume=-1;
    }
  }
}
int64_t sumo=0;
int64_t counto=0;  
for(int i=0;i<n;i++){
  sumo+=d[i];
  if(i%2==1){
    if(sumo<=0){
      counto+=1-sumo;
      sumo=1;    
    }
  }
    else{
      if(sumo>=0){
        counto+=sumo+1;
        sumo=-1;
       }
    }
}
cout << min(counte,counto) << endl;
}