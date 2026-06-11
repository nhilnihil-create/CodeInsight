#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  string s;
  cin>>n>>s;
  for(int p=0;p<4;++p){
    string t(n,'?');
    t[0]=a=(p%2?'S':'W');
    t[1]=b=(p/2%2?'S':'W');
    for(int i=1;i<=n;++i){
      int prev=(i%n==0?n-1:i-1);
      int next=(i==n-1?0:i%n+1);
      if((s[i%n]=='o'&&t[i%n]=='S')||(s[i%n]=='x'&&t[i%n]=='W')){
        t[next]=t[prev];
      }
      else t[next]=(t[prev]=='S'?'W':'S');
    }
    if(t[0]==a&&t[1]==b){
      cout<<t<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}
