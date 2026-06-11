#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int ans = 0;
  while(a %2 == 0 && b%2 == 0 && c%2 == 0){
    int aa = a;
    int bb = b;
    int cc = c;
    a = bb/2 + cc/2;
    b = aa/2 + cc/2;
    c = aa/2 + bb/2;
    ans++;
    if(a == b && b == c){
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
}