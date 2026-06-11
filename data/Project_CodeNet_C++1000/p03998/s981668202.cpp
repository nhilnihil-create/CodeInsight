
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s[3];
  rep(i, 3) cin >> s[i];
  int a = 0, b = 0, c = 0, p = 0;
  char ch;
  int A = s[0].size(), B = s[1].size(), C = s[2].size();
  while(1){
    if(p == 0 && a == A){
      cout << "A" << endl;
      return 0;
    }
    if(p == 1 && b == B){
      cout << "B" << endl;
      return 0;
    }
    if(p == 2 && c == C){
      cout << "C" << endl;
      return 0;
    }
    if(p == 0) ch = s[0][a++];
    else if(p == 1) ch = s[1][b++];
    else ch = s[2][c++];
    p = ch - 'a';
    //cout << "p:" << p << endl;
  }
    
    
  return 0;
}