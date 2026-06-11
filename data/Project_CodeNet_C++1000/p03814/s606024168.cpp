#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  string s;
  cin >> s;
  int i=0,j =s.size()-1;
  while(1) {
    if(s[i]=='A') break;
    i++;
  }
  while(1) {
    if(s[j]=='Z') break;
    j--;
  }
  cout << j-i+1 << endl;
}