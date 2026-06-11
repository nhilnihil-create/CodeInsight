#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int H, W;
vector<int> cnt(26, 0), block(4, 0);
int main(){
  cin >> H >> W;
  vector<string> a(H);
  REP(i, H){
    cin >> a[i];
    REP(j, W){
      cnt[a[i][j]-'a']++;
    }
  }
  sort(cnt.begin(), cnt.end());
  REP(i, (H+1)/2){
    REP(j, (W+1)/2){
      int r = 1;
      if((i+1)*2 <= H){
        r*=2;
      }
      if((j+1)*2 <= W){
        r*=2;
      }
      block[r-1]++;
    }
  }
  REPR(i, 25){
    REPR(j, 3){
      int diff = cnt[i] / (j+1);
      int sa = min(diff, block[j]);
      cnt[i] -= sa*(j+1);
      block[j] -= sa;
    }
  }
  REP(i, 4){
    if(block[i]){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
