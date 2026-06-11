#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int x,y;
  cin>>x>>y;

  if(x==y) cout<<"Draw"<<endl;
  else if(min(x,y)!=1){
    if(x>y) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
  }
  else if(min(x,y)==1){
    if(x>y) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
  }

}
