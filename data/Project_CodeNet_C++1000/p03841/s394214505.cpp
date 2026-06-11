#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

typedef pair<int, int> p_ii;

int main() {
  int N; cin >> N;
  p_ii pos[N]; rep(i,N) { int x; cin >> x; pos[i] = make_pair(i,x-1); }

  queue<int> part;
  sort(pos,pos+N,[](const p_ii &x, const p_ii &y){ return x.second<y.second; });
  for (auto x: pos) rep(i,x.first) part.push(x.first);
  // reverse(pos,pos+N);
  for (auto x: pos) rep(i,(N-1)-x.first) part.push(x.first);
  // while(!part.empty()) { cout << part.front() << " "; part.pop(); } cout << endl;

  // reverse(pos,pos+N);
  // rep(i,N) cout << pos[i].first << "->" << pos[i].second << endl;
  int ipos = 0;
  int result[N*N];
  int count[N] = {};
  rep(i,pow(N,2)) {
    if (pos[ipos].second==i) {
      if (pos[ipos].first==count[pos[ipos].first]) {
        result[i] = pos[ipos].first+1;
        count[pos[ipos].first]++;
        ipos++;
      }
      else {
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      result[i] = part.front()+1;
      count[part.front()]++;
      part.pop();
    }
  }
  cout << "Yes" << endl;
  rep(i,pow(N,2)) cout << result[i] << " "; cout << endl;
  return 0;
}