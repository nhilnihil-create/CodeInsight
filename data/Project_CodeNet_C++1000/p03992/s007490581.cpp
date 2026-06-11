#include <bits/stdc++.h>
using namespace std;
#define LONGLONGMAX 9223372036854775807
#define LONGLONGMIN -9223372036854775807
#define INTMAX 32767
#define INTMIN -32767
#define ROUNDUP(divisor,dividend) (divisor + (dividend - 1)) / dividend
 string s;
int main(){
  cin >> s;
  for (size_t i = 0; i < 4; i++) {
    cout << s[i];
  }
  cout << ' ';
  for (size_t i = 4; i < s.length(); i++) {
    cout << s[i];
  }
  cout << endl;
}
