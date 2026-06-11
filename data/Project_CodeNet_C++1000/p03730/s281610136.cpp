#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll A,B,C;cin>>A>>B>>C;
  string ans = "NO";

  for(int i = 1; i < B+1; i ++) {
    int tmp = i*A % B;
    if (tmp == C) {
      ans = "YES";
    }
  }

  cout << ans << endl;
  return 0;
}