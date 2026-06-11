#include<bits/stdc++.h>
using namespace std;
signed main(){
  int a,b;
  string c,d;
  cin>>a>>b;
  for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
      cin>>c;
      if(c=="snuke"){
        d=64+j;
        cout<<d<<i<<"\n";
      }
    }
  }
}