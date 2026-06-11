#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t A,B,C;
  cin>>A>>B>>C;
  bool Q=false;
  for(int i=1;i<10000000;i++){
    if((A*i)%B==C){
      Q=true;
      break;
    }
  }
  if(Q){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
  
  
      
