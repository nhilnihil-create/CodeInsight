#include<bits/stdc++.h>
using namespace std;
signed main(){
  int h,w;
  string c,d;
  cin>>h>>w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin>>c;
      if(c=="snuke"){
	d=64+j;
	cout<<d<<i<<"\n";
      }
    }
  }
}
