#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int W, a, b;
  cin >> W >> a >> b;

  if (a + W < b){
    cout << b - (a + W) << endl;
  }
  else if (a + W == b)
  {
    cout << 0 << endl;
  }
  else if (b + W < a)
  {
    cout << a - (b + W) << endl;
  }
  else
  {
    cout << 0 << endl;
  }
  
  
  
}