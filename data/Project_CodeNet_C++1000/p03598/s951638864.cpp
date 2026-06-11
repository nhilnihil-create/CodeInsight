#include<iostream>
using namespace std;
int main(){
  int N;
  int K;
  cin>>N>>K;
  int X[N]={};
  int i;
  for(i=0;i<=N-1;i++){
  cin>>X[i];
  }
  int ans=0;
  int adis=0;
  int bdis=0;
  for(i=0;i<=N-1;i++){
  adis=X[i];
  bdis=K-X[i];
  if(adis<=bdis){
  ans+=adis*2;
  }
  else{
  ans+=bdis*2;
  }  
  }
  cout<<ans;
}