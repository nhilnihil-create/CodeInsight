#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,M;cin>>N>>M;
  if(M/N<2){
    cout<<min(N,M/2)<<endl;
  }
  else{
    cout<<(N*2+M)/4<<endl;
  }
}