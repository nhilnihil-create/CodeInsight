#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int64_t result = 0;
  for (int tmp=0; tmp<(1<<(S.size()-1)); tmp++) {
    bitset<10> bit_tmp(tmp);

    string S_n;
    for (int cnt=0; cnt<S.size(); cnt++) {
      S_n += S.at(cnt);
      if( bit_tmp.test(cnt) ) {
        result += stoll(S_n);
        S_n = "";
      }
    }

    if (S_n != "") {
      result += stoll(S_n);
    }
  }

  cout << result << endl;
  
  return 0;
}