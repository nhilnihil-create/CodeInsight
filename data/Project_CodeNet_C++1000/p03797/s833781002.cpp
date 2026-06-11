#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  cin>>N>>M;
  if(M>=N*2){
    cout<<N+(M-2*N)/4<<endl;
  }
  else{
    cout<<M/2<<endl;
  }
}
