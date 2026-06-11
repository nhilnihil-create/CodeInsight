#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  sort(A.begin(),A.end());
  int left=-1; int right=N; int mid;
  while(1<right-left){
    mid=left+(right-left)/2;
    int64_t sum=0;
    for(int i=0;i<=mid;i++)
      sum+=A.at(i);
    bool x=true;
    for(int i=mid+1;i<N;i++){
    if(A.at(i)<=2*sum)
      sum+=A.at(i);
      else{x=false; break;}
    }if(x)right=mid;
    else
      left=mid;
  
  }int ans=N-right;
  cout<<ans<<endl;
   return 0;
}