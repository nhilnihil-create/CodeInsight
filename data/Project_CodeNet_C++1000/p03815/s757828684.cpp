#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin>>N;
  if(N<=0){
    cout<<0<<endl;
  }
  else if(N%11==0){
    cout<<N/11*2<<endl;
  }
  else if(N%11<=6){
    cout<<N/11*2+1<<endl;
  }
  else{
    cout<<N/11*2+2<<endl;
  }
}
