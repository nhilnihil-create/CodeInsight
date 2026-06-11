#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using ll = long long;

int main(){
  string S;
  cin >> S;
  ll sum = 0;
  int len = S.size()-1;
  for (int tmp = 0; tmp < (1 << len); tmp++) {
    string str;
    str = S[0];
    rep(i,len){
      if ((tmp>>(len-1-i))&1) {
        sum += stoll(str);
        str = S[i+1];
      }
      else  str += S[i+1];
    }
    sum += stoll(str);
  }
  cout << sum << endl;
}