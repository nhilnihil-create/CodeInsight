#include<bits/stdc++.h>
using namespace std;
int main(){
int N,T;
  cin>>N>>T;
  int ans=T;
  vector<int>time(N);
  for(int i=0;i<N;i++)
  cin>>time.at(i);
  for(int i=0;i<N-1;i++){
  int time1=time.at(1+i)-time.at(i);
    if(time1<=T)
      ans+=time1;
    else
      ans+=T;
  }cout<<ans<<endl;
   return 0;
}