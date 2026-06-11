#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  long long MOD=1000000007;
  cin>>N>>M;
  if(abs(N-M)>=2){
    cout<<0<<endl;
  }
  else{
    long long NN=1;
    long long MM=1;
    for(int i=0;i<N;i++){
      NN=(NN*(i+1))%MOD;
    }
    for(int i=0;i<M;i++){
      MM=(MM*(i+1))%MOD;
    }
    if(N==M){
      cout<<(2*NN*MM)%MOD<<endl;
    }
    else{
      cout<<(NN*MM)%MOD<<endl;
    }
  }
}
    
    
