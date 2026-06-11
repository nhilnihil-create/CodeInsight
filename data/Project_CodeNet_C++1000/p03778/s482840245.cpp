#include <bits/stdc++.h>
using namespace std;

int main() {
  int w,a,b;
  cin >>w>>a>>b;
  if(a>b){
    if(a-b-w<=0){
      cout<<0<<endl;
    }else{
      cout<<a-b-w<<endl;
    }
  }else{
    if(b-a-w<=0){
      cout<<0<<endl;
    }else{
      cout<<b-a-w<<endl;
    }
  }
  return 0;
}