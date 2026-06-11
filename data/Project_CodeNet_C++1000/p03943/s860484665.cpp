#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int s=0;
  s=max({a,b,c});
  if(s*2==a+b+c){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
}