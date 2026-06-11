#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N, M; cin >> N >> M;
  queue<int> A[N];
  rep(i,N) rep(j,M) { int tmp; cin >> tmp; tmp--; A[i].push(tmp);}

  int result = INF;
  set<int> used;
  rep(i,M) {
    int count[M] = {};
    rep(i,N) {
      while(used.find(A[i].front())!=used.end()) A[i].pop();
      count[A[i].front()]++;
    }
    int m = 0, num = 0;
    for (auto i: used) count[i] = 0;
    rep(i,M) if (count[i]>m) { m = count[i]; num = i; }
    used.insert(num);
    result = min(result, m);
    rep(i,N) if (A[i].front()==num) A[i].pop();
    // rep(i,M) cout << count[i] << " "; cout << "->" << m ; cout << endl;
  }
  cout << result << endl;
  return 0;
}