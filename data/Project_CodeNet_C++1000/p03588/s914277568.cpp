#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e;
  cin>>a;
  d=0;
  e=0;
  for(int i=0;i<a;i++){
    cin>>b>>c;
    if(b>d){
      d=b;
      e=c;
    }
  }
  cout<<d+e<<endl;
}