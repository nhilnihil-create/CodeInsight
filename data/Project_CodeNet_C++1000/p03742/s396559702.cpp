#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main(){
  i64 x,y;
  cin >> x >> y;
  if(x == 0 && y == 0){
    cout << "Brown" << endl;
    return 0;
  }

  // | X - Y - 3i| <= 1 に必ずできる
  if(abs(x - y) <= 1){
    cout << "Brown" << endl;
  }
  else{
    cout << "Alice" << endl;
  }
}
