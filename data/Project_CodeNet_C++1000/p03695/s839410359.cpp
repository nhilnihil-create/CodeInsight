#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int n;
  cin>>n;
  
  vector<int>rate(n);
  for(int i=0;i<n;i++){
    cin>>rate.at(i);
  }
  
  int count[9]={0};
  for(int i=0;i<n;i++){
    if(rate.at(i)<400)count[0]++;
    else if(rate.at(i)<800)count[1]++;
    else if(rate.at(i)<1200)count[2]++;
    else if(rate.at(i)<1600)count[3]++;
    else if(rate.at(i)<2000)count[4]++;
    else if(rate.at(i)<2400)count[5]++;
    else if(rate.at(i)<2800)count[6]++;
    else if(rate.at(i)<3200)count[7]++;
    else count[8]++;
  }
  
  int ans=0;
  for(int i=0;i<=7;i++){
    if(count[i]!=0)ans++;
  }
  
  if(count[8]==0){
    cout<<ans<<' '<<ans<<endl; 
  }else{
    if(ans==0)cout<<1<<' '<<ans+count[8]<<endl;
    else cout<<ans<<' '<<ans+count[8]<<endl;
  }
  
  return 0;
}
