#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  vector<int> ab;

  for (int a = 0; a * A * 100 <= F; a++) {
    for (int b = 0; b * B * 100 + a * A * 100 <= F; b++) {
      ab.emplace_back(a*A*100 + b*B*100);
    }
  }
  vector<int> cd;
  for (int c = 0; c * C <= F; c++) {
    for (int d = 0; d * D <= F; d++) {
      cd.emplace_back(c*C + d*D);
    }
  }

  sort(ab.begin(), ab.end());
  sort(cd.begin(), cd.end());

  double mx = -1;
  P res;
  res.first = 100*A;
  res.second = 0;
  for (int i = 1; i < ab.size(); i++) {
    for (int j = 1; j < cd.size(); j++) {
      if (ab[i] + cd[j] > F) break;
      if (100 * cd[j] > ab[i] * E) break;
      double tmp = (1.0 * cd[j]) / (1.0 * (ab[i] + cd[j]));
      if (mx < tmp) {
        res.first = ab[i] + cd[j];
        res.second = cd[j];
        mx = tmp;
      }
    }
  }
  cout << res.first << " " << res.second << endl;
} 