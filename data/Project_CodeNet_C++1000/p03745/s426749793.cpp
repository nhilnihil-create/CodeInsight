#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
const double pi = 3.141592653589793238;


int main() {
  int N; cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a.at(i);

  int sw;
  int be = 0;

  int cnt = 0;
  for(int i = 0; i < N-1; i++) {
    if(a.at(i+1) - a.at(i) > 0) sw = 1;
    else if(a.at(i+1) - a.at(i) < 0) sw = -1;
    else if(a.at(i+1) - a.at(i) == 0) {
      sw = be;
      continue;
    }

    // cout << "be:" << be << ", sw:" << sw << endl;
    if(i == 0) {be = sw; continue;}
    if(sw + be != 0) {
      be = sw;
    } else {
      cnt++;
      be = 0;
    }
  }

  cout << cnt+1 << endl;

}
