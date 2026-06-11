#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int ab = a+b,ac = a+c,bc = b+c;
  if(ab <ac && ab<bc){
    cout << ab << endl;
    return 0;
  }
  else if(ac<ab && ac<bc){
    cout << ac << endl;
    return 0;
  }
  cout << bc << endl;
}
