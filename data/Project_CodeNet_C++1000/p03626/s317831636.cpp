#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  string s1,s2;
  cin>>s1>>s2;
  vector<int>A(N,0);
  for(int i=0;i<N;i++){
  if(s1.at(i)==s2.at(i))
    A.at(i)=1;
  }
  if(A.at(0)==1){
   int64_t ans=3;
    int a=1;
    int x=0;
    for(int i=0;i<N;i+=a){
     if(A.at(i)==1) a=1; 
      else a=2;
      if(x==0 && A.at(i)==0)
        ans=(3*ans)%1000000007;
      else if(x==1)
        ans=(2*ans)%1000000007;
      else ans=ans;
       x=A.at(i);
    }cout<<ans<<endl;
  
  }else{
   int64_t ans=2;
    int a=2;
    int x=0;
    for(int i=0;i<N;i+=a){
     if(A.at(i)==1) a=1; 
      else a=2;
      if(x==0 && A.at(i)==0)
        ans=(3*ans)%1000000007;
      else if(x==1)
        ans=(2*ans)%1000000007;
      else ans=ans;
       x=A.at(i);
    }cout<<ans<<endl;
  }
   return 0;
}