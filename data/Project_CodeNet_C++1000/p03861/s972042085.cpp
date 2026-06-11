#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long long a, b, x, h;
  cin >> a >> b >> x;
  if(a == 0){
    cout << b / x + 1 <<endl;
    return 0;
  }
  if(a < x){
    h = x;
  } else{
    if(a % x != 0){
     h = a + (x - a % x);
    } else {
      h = a;
    }
  }
  if(h > b){
    cout << 0 <<endl;
  } else{
    cout << (b - h) / x  + 1<<endl; 
  }
}
