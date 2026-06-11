#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int sx,sy,gx,gy; cin >> sx >> sy >> gx >> gy;

  string ans = "";
  for(int i = sx; i < gx; i++){
    ans += "R";
  }
  for(int i = sy; i < gy; i++){
    ans += "U";
  }
  for(int i = sx; i < gx; i++){
    ans += "L";
  }
  for(int i = sy; i < gy; i++){
    ans += "D";
  }

  ans += "D";
  for(int i = sx; i < gx; i++){
    ans += "R";
  }
  ans += "RU";
  for(int i = sy; i < gy; i++){
    ans += "U";
  }
  ans += "LU";
  for(int i = sx; i < gx; i++){
    ans += "L";
  }
  ans += "LD";
  for(int i = sy; i < gy; i++){
    ans += "D";
  }
  ans += "R";

  cerr << ans << endl;
  cout << ans << endl;

}
