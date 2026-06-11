#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n,s;cin>>n;
  int m=101,c;
  for(int i=0;i<n;++i){
    cin>>s;
    if(s%10!=0)m=min(m,s);
    c+=s;
  }
  if(m==101)m=0;
  if(c%10!=0)cout<<c;
  else{
    c-=m;
    if(c&10!=0)cout<<c;
    else cout<<0;
  }
}