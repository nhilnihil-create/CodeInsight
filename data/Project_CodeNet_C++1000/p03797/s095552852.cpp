#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t N,M;
  cin>>N>>M;
  if((M/2)<=N)
    cout<<M/2<<endl;
  else{
  int64_t ans=(N+(M/2))/2;
    cout<<ans<<endl;
  
  }
    return 0;
}