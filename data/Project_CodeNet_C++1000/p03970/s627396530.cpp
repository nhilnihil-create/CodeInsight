#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main(void){
  int i,ans=0;
  string s,t="CODEFESTIVAL2016";
  cin >> s;
  for (i=0;i<16;i++) if (s[i]!=t[i]) ans++;
  cout << ans << endl;
  return 0;
}