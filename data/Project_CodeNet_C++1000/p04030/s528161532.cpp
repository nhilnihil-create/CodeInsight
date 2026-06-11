#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  char s;
  deque<char> dq;
  while (cin >> s) {
    //cout << s << endl;
    if (s == '0') {
      dq.push_back('0');
      continue;
    }
    if (s == '1') {
      dq.push_back('1');
      continue;
    }
    if (s == 'B' && (!dq.empty())) {
      dq.pop_back();
      continue;
    }
  }
  while(!dq.empty()) {
    cout << dq.front();
    dq.pop_front();
  }
  cout << endl;
  return 0;
}