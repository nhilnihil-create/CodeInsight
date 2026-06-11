#include<bits/stdc++.h>
using namespace std;
int main(){
   int64_t N,P;
  cin>>N>>P; int c=0;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
    int64_t a; cin>>a;
    a%=2;if(a==1)c++;
    A.at(i)=a;
  }if(c==0){
  if(P==1)
    cout<<0<<endl;
    else{int64_t ans=pow(2,N);cout<<ans<<endl;}
  
  }else{int64_t ans=pow(2,N-1); cout<<ans<<endl;}
  return 0;
}