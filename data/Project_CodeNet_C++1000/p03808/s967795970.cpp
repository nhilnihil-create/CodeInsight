#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;cin>>N;
  vector<int64_t>A(N);
  int64_t sum=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);sum+=A.at(i);
  }int64_t n=(N*(N+1))/2;
  if(sum%n!=0)
    cout<<"NO"<<endl;
  else{
  int64_t a=sum/n;bool x=true;int64_t Sum=0;
    for(int i=0;i<N;i++){
    int64_t b=A.at((i+1)%N)-A.at(i);
      b-=a;
      if(b%N!=0 || 0<b){x=false;break;}
      else{Sum+=(b/N);}
    }
  if(!x)cout<<"NO"<<endl;
    else{
    if(Sum==-a)
      cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
     }
   }
  return 0;
}