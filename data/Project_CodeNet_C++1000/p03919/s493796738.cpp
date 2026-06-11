#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;

  for(int i=0; i<h; i++){
    for(char c='A'; c<'A'+w; c++){
      string s;
      cin>>s;
      if(s=="snuke"){
        cout<<c<<i+1<<endl;
        goto end;
      }
    }
  }

  end:;
  
}