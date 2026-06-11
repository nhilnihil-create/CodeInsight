#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  string s; cin >> s;
  int begin=0;
  int end=0;

  int i = 0;
  while(true) {
    if(s[i] == 'A') {
      begin = i;
      break;
    }
    i++;
  }

  int j = s.size()-1;
  while(true) {
    if(s[j] == 'Z') {
      end = i;
      break;
    }
    j--;
  }
  cout << j-i+1 << endl;
  return 0;
}