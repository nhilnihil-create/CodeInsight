#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    string str; cin >> str;
  
    int x = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(str.at(i) == 'I') {
        x++;
      } else {
        x--;
      }
      if(ans < x) ans = x;
    }
  
    cout << ans << endl;

    return 0;
}