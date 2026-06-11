#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int cnt = 0;
  for(int i = a; i <= b; i++){
    for(int j = c; j <= d; j++ ){
      if(i == j) cnt++;
    }
  }
  if(cnt >= 2){
  cout << cnt - 1 << endl;
  } else cout << 0 << endl;
 }
