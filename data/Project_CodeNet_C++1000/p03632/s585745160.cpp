#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  
  cin >> a >> b >> c >> d;
  
  if((c >= a && c <= b) && (d >= a && d <= b)){
    //  A------B
    //    C--D
    cout << d - c;
  }else if((a >= c && a <= d) && (b >= c && b <= d)){
    //    A--B
    //  C------D
    cout << b - a;
  }else if(a <= c && (b >= c && b <= d)){
    //   A----B
    //     C----D
    cout << b - c;
  }else if(c <= a && (d >= a && d <= b)){
    //     A----B
    //   C----D
    cout << d - a;
  }else{
    //          A----B
    //   C----D
    cout << 0;
  }
}
