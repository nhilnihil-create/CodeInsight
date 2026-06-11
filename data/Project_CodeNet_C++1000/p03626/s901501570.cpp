#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N;
  cin >> N;

  string S1,S2;
  cin >> S1 >> S2;

  int now = 0;
  long long ans;
  char con;
  if(S1.at(0) == S2.at(0)) {
    con = 'l';
    ans = 3;
    now++;
  }else {
    con = 'c';
    ans = 6;
    now += 2;
  }

  for(int i = now;i < N;i++) {
    if(con == 'l') {
      ans *= 2;
      if(S1.at(i) != S2.at(i)) {
        con = 'c';
        i++;
      }
    }else {
      if(S1.at(i) == S2.at(i)) con = 'l';
      else {
        ans *= 3;
        i++;
      }
    }
    ans %= MOD;
  }

  cout << ans << endl;
}

