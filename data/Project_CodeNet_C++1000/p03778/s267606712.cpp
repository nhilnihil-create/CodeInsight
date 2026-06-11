#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {

  int w, a , b;
  cin >> w >> a >> b;
  int c = min(a,b);
  int ans = 0;
  if(c == a) {
    for(int i = 0; i < 10e10; i++) {
      if(b <= a+w ) {
        cout << ans << endl;
        return 0;
      } else {
        ans++;
        b--;
      }
    }
  } else if(c == b) {
    for(int i = 0; i < 10e10; i++) {
      if(b+w >= a) {
        cout << ans << endl;
        return 0;
      } else {
        ans++;
        b++;
      }
    }
  }
}