#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int ans=1;
  while(N>1){
    N=N/2;
    ans*=2;
  }
  cout<<ans<<endl;
}