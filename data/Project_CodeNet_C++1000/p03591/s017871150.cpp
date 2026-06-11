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
  cout << (s[0]=='Y'&&s[1]=='A'&&s[2]=='K'&&s[3]=='I' ? "Yes":"No") << endl; 
}
