#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int
main ()
{
  string s, t ="CODEFESTIVAL2016"; cin >> s;
  int ans = 0;
  rep(i, s.size()){
      if(s.at(i) != t.at(i)) ans++; 
  }
  cout << ans << endl;
  return 0;
}
