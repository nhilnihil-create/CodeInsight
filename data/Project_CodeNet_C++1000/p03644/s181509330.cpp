#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  if(n < 4){
    cout << 2 << endl;
    return 0;
  }
  if(n < 8){
    cout << 4 << endl;
    return 0;
  }
  if(n < 16){
    cout << 8 << endl;
    return 0; 
  }
  if(n < 32){
    cout << 16 << endl;
    return 0;
  }
  if(n < 64){
    cout << 32 << endl;
    return 0;
  }
  else{
    cout << 64 << endl;
    return 0;
  }
}