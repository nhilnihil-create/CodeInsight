#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,i=1;
  cin>>N;
  for(;true;i++){
    if(i*(i+1)/2>=N)
      break;
  }
  for(;i>0;i--){
    if(N>=i){
      cout<<i<<endl;
      N-=i;
    }
    if(N==0)
      break;
  }
}