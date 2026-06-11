#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  
  if(x==y) cout << 0 << endl;
  else if(x==0) cout << max(y,-1*y)+(y<0) << endl;
  else if(x<0){
    if(y==0) cout << -1*x << endl;
    else if(0<y){
      x*=-1;
      cout << max(x-y,y-x)+1 << endl;
    } else{
      if(x<y) cout << y-x << endl;
      else cout << x-y+2 << endl;
    }
  }
  else{ //0<x
    if(y==0) cout << x+1 << endl;
    else if(0<y){
      if(x<y) cout << y-x << endl;
      else cout << x-y+2 << endl;
    }
    else {
      y*=-1;
      cout << max(x-y,y-x)+1 << endl;
    }
  }
}