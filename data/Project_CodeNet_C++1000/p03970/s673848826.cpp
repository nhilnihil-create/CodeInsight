#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  /*cin>>a>>b>>c;
  if(a>b) cout<<"NO"<<'\n';
  else if(a+b>=c) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';*/
  string s,code="CODEFESTIVAL2016";
  cin>>s;
  int sum=0;
  for(int i=0;i<16;i++){
    if(s[i]!=code[i]) sum++;
  }
  cout<<sum<<'\n';
  return 0;
}
