#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll m,n,i,a=1,p=1000000007;
  cin >> n >> m;
  if(abs(m-n)>1){
    cout << 0 << endl;
    return 0;
  }
  for(i=1;i<=n;i++){
    a=(a*i)%p;
  }
  for(i=1;i<=m;i++){
    a=(a*i)%p;
  }
  if(m==n){
    a=(a*2)%p;
  }
  cout << a << endl;
}