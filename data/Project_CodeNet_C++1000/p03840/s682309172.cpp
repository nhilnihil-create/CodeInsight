#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t ai,ao,at,aj,al,as,az;
  cin>>ai>>ao>>at>>aj>>al>>as>>az;
  int64_t ans=ao+ai+aj+al;if(ai!=0 && aj!=0 && al!=0){
  int64_t sum=0;sum+=ai%2;sum+=al%2;sum+=aj%2;
    if(sum==2 ||sum==1)
      ans--;
   }else{
  int64_t sum=0;sum+=ai%2;sum+=al%2;sum+=aj%2;
    ans-=sum;
  }
  cout<<ans<<endl;
  return 0;
}
