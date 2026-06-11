#include <bits/stdc++.h>
using namespace std;

int main(){
  int SI=0;
  string s;
  cin >> s;
  SI += s.size();
  cout << s[0] << SI-2 << s[SI-1] << endl;
}
