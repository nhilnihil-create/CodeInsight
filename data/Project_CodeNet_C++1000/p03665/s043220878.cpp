#include <bits/stdc++.h>
using namespace std;
//解説AC
int main() {
  int n,p; cin >>n>>p;
  int kisuu=0;
  int guusuu=0;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if( x%2==1 )kisuu++;
    else guusuu++;
  }
  if(p==1&&kisuu==0){
    cout <<0<<endl;
    return 0;
  }
  long long kotae=0;
  if(p==0&&kisuu==0)kotae=pow(2,n);
  else kotae=pow(2,n-1);
  cout<<kotae<<endl;
  return 0;
}