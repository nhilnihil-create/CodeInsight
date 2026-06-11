#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  char a,b;
  cin >> a >> b;
  if( a == 'H' ){
    if( b == 'H' ){
      cout << 'H' << endl;
    }else{
      cout << 'D' << endl;
    }
  }else{
    if( b == 'H' ){
      cout << 'D' << endl;
    }else{
      cout << 'H' << endl;
    }
  }
  return 0;
}