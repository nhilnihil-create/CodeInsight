#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007; 
int main() {
  int n,m;
  cin>>n>>m;
  long long kotae=1;
  if(abs(m-n)>1){
    cout<<0<<endl;
    return 0;
  }else if(n==m){
    kotae=n+m;
    kotae%=MOD;
    kotae*=n;
    kotae%=MOD;
    for(int i=1;i<n;i++){
      //cout<<kotae<<" ";
      kotae*=(n-i);
      kotae%=MOD;
      kotae*=(n-i);
      kotae%=MOD;
    }
  }else{
    for(int i=0;i<min(n,m);i++){
      kotae*=(n-i);
      kotae%=MOD;
      kotae*=(m-i);
      kotae%=MOD;
    }    
  }
  cout<<kotae<<endl;
  return 0;
}
    
