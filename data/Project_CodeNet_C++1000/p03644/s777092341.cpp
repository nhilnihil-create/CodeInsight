#include <bits/stdc++.h>
using namespace std;

bool is_pow2( int x)
{
    if (x == 0) {
        return false;
    }
    return (x & (x - 1)) == 0;
}

int main(void){
    
  int N;
  cin >> N;
  for(int i=N;i>=1;i--){
      if(is_pow2(i)){
          cout << i << endl;
          break;
      }
  }
}