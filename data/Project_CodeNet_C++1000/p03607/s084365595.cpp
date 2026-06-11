#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll N; cin>>N;
  map<int, bool> A;

  rep(i, N) {
    ll tmp; cin>>tmp;
    if(A.count(tmp)) {
      A.erase(tmp);
    } else {
      A.insert(make_pair(tmp, true));
    }
  }

  cout << A.size() << endl;
  return 0;
}