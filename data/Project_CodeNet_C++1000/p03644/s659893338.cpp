#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int ans=0;
  for(int i=0; i<7; i++){
    N/=2;
    if(N<1){
      ans=i;
      break;
    }
  }
  int a=pow(2,ans);
  cout<<a<<endl;
}