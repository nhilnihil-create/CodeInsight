#include<bits/stdc++.h>
using namespace std;
int main(){
  long A[7];
  for(int i=0;i<7;i++)cin>>A[i];
  long ans=(A[0]/2+A[3]/2+A[4]/2)*4;
  if(A[0]>0&&A[3]>0&&A[4]>0){
    ans=max(ans,((A[0]-1)/2+(A[3]-1)/2+(A[4]-1)/2)*4+6);
  }
  ans+=A[1]*2;
  cout<<ans/2;
}