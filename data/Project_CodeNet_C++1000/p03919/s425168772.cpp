#include <bits/stdc++.h>
using namespace std;
#define LONGLONGMAX 9223372036854775807
#define LONGLONGMIN -9223372036854775807
#define INTMAX 32767
#define INTMIN -32767
#define ROUNDUP(divisor,dividend) (divisor + (dividend - 1)) / dividend
string s[26][26]; int h,w; string ans;
int main(){
  cin >> h >> w;
  for (size_t y = 0; y < h; y++) {
    for (size_t x = 0; x < w; x++) {
      cin >> s[y][x];
      if(s[y][x] == "snuke"){
        ans = 'A'+x;
        ans+= to_string(y+1);
      }
    }
  }
  cout << ans << endl;
}
