#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007; 
int main() {
  int n,m;
  cin>>n>>m;
  long long cnt_n;
  long long cnt_m;
  long long kotae=2;
  long long sa=abs(n-m);
  if(sa==1)kotae--;
  else if(sa>1){
    cout<<0<<endl;
    return 0;
  }
  for(long long i=n;i>=2;i--){
    kotae*=i;
    kotae%=MOD;
  }
  kotae%=MOD;
  for(long long i=m;i>=2;i--){
    kotae*=i;
    kotae%=MOD;
  }
  kotae%=MOD;
  cout<<kotae<<endl;
}
  

    
