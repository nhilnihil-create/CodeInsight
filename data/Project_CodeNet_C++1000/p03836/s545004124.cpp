#include<bits/stdc++.h>
using namespace std;
int main(){
  int SX,SY,TX,TY;
  cin>>SX>>SY>>TX>>TY;
  for(int M=0;M<TX-SX;M++){
    cout<<'R';
  }
  for(int M=0;M<TY-SY;M++){
    cout<<'U';
  }
  for(int M=0;M<TX-SX;M++){
    cout<<'L';
  }
  for(int M=0;M<TY-SY;M++){
    cout<<'D';
  }
  cout<<'D';
  for(int M=0;M<TX-SX;M++){
    cout<<'R';
  }
  cout<<'R';
  cout<<'U';
  for(int M=0;M<TY-SY;M++){
    cout<<'U';
  }
  cout<<'L';
  cout<<'U';
  for(int M=0;M<TX-SX;M++){
    cout<<'L';
  }
  cout<<'L';
  for(int M=0;M<TY-SY;M++){
    cout<<'D';
  }
  cout<<'D';
  cout<<'R'<<endl;
}