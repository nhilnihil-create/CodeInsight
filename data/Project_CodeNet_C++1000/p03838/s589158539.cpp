#include <bits/stdc++.h>
using namespace std;
int main(){
  long long X,Y;
  cin >> X >> Y;
  if(X == 0){
    if(Y < 0){
      cout << 1+abs(Y) << endl;
      return 0;
    }
    else{
      cout << abs(Y) << endl;
      return 0;
    }
  }
  else if(Y == 0){
    if(X>0){
      cout << 1+abs(X) << endl;
      return 0;
    }
    else{
      cout << abs(X) << endl;
      return 0;
    }
  }
  else if(abs(X) == abs(Y)){
    if(X != Y){
      cout << 1 << endl;
      return 0;
    }
    else{
      cout << 0 << endl;
      return 0;
    } 
  }
  bool ok = false;
  if((X >= 0 && Y >= 0) || (X<0 && Y<0)) ok = true;
  if(ok && X <= Y){
    cout << abs(abs(Y)-abs(X)) << endl;
    return 0;
  }
  else if(ok){
    cout << 2+abs(Y-X) << endl;
    return 0;
  }
  else{
   int Z = abs(abs(X)-abs(Y));
    cout << Z+1 << endl;
    return 0;
  }
}
