#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  long long A[N];
  int cnt=0;
  int ODN=0;
  int EN=0;
 
  for (int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]%2==0){
      EN++;
    }
    else ODN++;
  }
   //cout<<ODN<<" "<<EN<<endl;
  if((ODN==0)&&(EN==2)){
    cout<<"YES"<<endl;
    return 0;
  }
  if((ODN==1)&&(EN==1)){
    cout<<"NO"<<endl;
    return 0;
  }
  if((ODN==2)&&(EN==0)){
    cout<<"YES"<<endl;
    return 0;
  }    
 if((ODN%2==1)&&((EN+(ODN/2))%2==1)){
    cout<<"NO"<<endl;
    return 0;
  } 
  cout<<"YES"<<endl;
  
  return 0;
}
