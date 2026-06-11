#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x,y;
  cin >> x >> y;
  if( ( 0<=x && x<y )||( x<y && y<=0 ))
    cout << y-x << endl;
  else if(x*y>0)
    cout << x-y+2 << endl;
  else
  {if(x+y>0)
    cout << x+y+1 << endl;
  else
    cout << 1-x-y << endl;
  }
}
