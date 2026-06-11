#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t A,B,C;
  cin>>A>>B>>C;
  int64_t ans=0;
  if(A==B && B==C){
  if(A%2==0)
    cout<<-1<<endl;
    else
      cout<<0<<endl;
  
  }else{
  int64_t ans=0;
    for(int i=1; ;i++){
    if(A%2==0 && B%2==0 && C%2==0){
    int64_t a=(B+C)/2;
      int64_t b=(A+C)/2;
      int64_t c=(A+B)/2;
      A=a; B=b; C=c;
         ans=i;
    }else break;
    
    }cout<<ans<<endl;
  
 }
    return 0;
}
