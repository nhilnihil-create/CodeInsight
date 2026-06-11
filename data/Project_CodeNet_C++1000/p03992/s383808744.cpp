#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >>s;
  string s1, s2;
  for(int i = 0; i<4; i++) s1 += s[i];
  for(int i = 4; i<12; i++) s2 += s[i];
  cout << s1 << " " << s2 << endl;
  return 0;
}