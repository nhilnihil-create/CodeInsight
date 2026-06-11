#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n;
  cin>>n;
  
  vector<int>data(n);
  for(int i=0;i<n;i++){
   cin>>data.at(i); 
  }
  
  sort(data.begin(),data.end());
  
  int ans=0;
  
  for(int i=0;i<n;i++){
    ans+=data.at(i); 
  }
  
  if(ans%10==0){
   for(int i=0;i<n;i++){
    if(data.at(i)%10!=0){
      ans-=data.at(i);
      break;
    }
   }
  }
  
  if(ans%10!=0)cout<<ans<<endl;
  else cout<<'0'<<endl;
  
  return 0;
}