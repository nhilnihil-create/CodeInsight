#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

  int n;

  cin >> n;

  int ni=1;

  for(int i=0;i<8;i++){
    if(n < ni){
      cout << ni/2 << endl;
      break;
    }else if(n == ni){
      cout << ni << endl;
      break;
    }else{
      ni = ni * 2;
    }
  }

}