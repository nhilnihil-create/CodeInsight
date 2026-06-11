#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  int now=0;
  cin>>x;
  for(int i=1;i<1000000000;i++){
    now+=i;
    if(now>=x){
      cout<<i<<endl;
      return(0);
    }
  }
  return(0);
}
