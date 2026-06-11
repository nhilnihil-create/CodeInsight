#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;

  if(max(a, x)-min(a, x)>max(b, x)-min(b, x)){
    cout << 'B' << endl;
  }
  else{
    cout << 'A' << endl;
  }

return 0;  
}