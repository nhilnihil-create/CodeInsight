#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  long long ans=0;
  long long A[N+1];
  long long temp=0;
  
  if(N==1){
    cin>>temp;
    cout<<temp/2<<endl;
    return 0;
  }
  
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }
  
  for(int i=1;i<N;i++){
    temp=(A[i]+A[i+1])/2;
    //cout<<i<<" "<<temp<<" "<<A[i]<<" "<<A[i+1]<<endl;
    ans+=temp;
    if(temp>0){
      A[i+1]=A[i]+A[i+1]-temp*2;
    }
  }
  
  cout<<setprecision(20)<<ans<<endl;
  return 0;
}

 