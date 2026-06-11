#include <bits/stdc++.h>
using namespace std;
 
int main() {
int a,b,c,d;
  cin>>a>>b>>c>>d;
  int e= max(a,c);
  int f=min(b,d);
  if(f-e>=0){
    cout<<f-e<<endl;
  }
  else{
    cout<<0<<endl;
  }
}