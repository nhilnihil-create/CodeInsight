#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,T;
  cin>>N>>T;
  int t[N];
  for(int i=0;i<N;i++){
    cin>>t[i];
  }
  
  int ans=T;
  for(int i=0;i<N-1;i++){
    if(t[i+1]-t[i]<T){
      ans+=t[i+1]-t[i];
    }
    else{
      ans+=T;
    }
  }
  cout<<ans<<endl;
}