#include<bits/stdc++.h>
using namespace std;

int main(){

  char a,b;
  cin >> a >> b;
  
  if(a=='H'){
  	if(b=='H')cout << 'H';
    else cout << 'D';
  }else{
  	if(b=='H')cout << 'D';
    else cout << 'H';
  }
  return 0;
}