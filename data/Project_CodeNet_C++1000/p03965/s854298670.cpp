#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  string s;
  cin >> s;

  int p = 0;
  for(int i = 0;i < s.size();i++) {
    if(s.at(i) == 'p') p++;
  }

 int n = s.size();
 if(n % 2 != 0) n--;
 cout << n / 2  - p<< endl;
}
