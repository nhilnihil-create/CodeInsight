#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  int x,y,z,count;
  count = 0;
  cin >> a >> b >> c;
  while(true){
    if(a%2==1 || b%2==1 || c%2==1){
      cout << count << endl;
      break;
    }
    else if(a==b && b==c && c==a){
      cout << -1 << endl;
      break;
    }
    x = b/2 + c/2;
    y = a/2 + c/2;
    z = a/2 + b/2;
    count++;
    if(x%2==1 || y%2==1 || z%2==1){
      cout << count << endl;
      break;
    }
    else{
      a = y/2 + z/2;
      b = x/2 + z/2;
      c = x/2 + y/2;
      count++;
    }
  }
}