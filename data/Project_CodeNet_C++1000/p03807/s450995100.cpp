#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  c=0;
  b=0;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>d;
    if(d%2==0){
      c++;
    }
    else{
      b++;
    }
  }
  if(c==0||b==0){
    cout<<"YES"<<endl;
  }
  else if(b%2==0){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}