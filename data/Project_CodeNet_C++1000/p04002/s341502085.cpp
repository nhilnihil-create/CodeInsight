#include <iostream>
#include <set>
#include <cstring>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

int H, W;
ll ans[10];
set<P> st;

void calc(int a, int b) {
  int ssi = max(a - 2, 1);
  int ssj = max(b - 2, 1);
  int ggi = min(a, H - 2);
  int ggj = min(b, W - 2);
  for (int si = ssi; si <= ggi; si++) {
    for (int sj = ssj; sj <= ggj; sj++) {
      int cnt = 0;
      for (int i = si; i < si + 3; i++) {
	for (int j = sj; j < sj + 3; j++) {
	  if (st.find(P(i, j)) != st.end()) {
	    cnt++;
	  }
	}
      }
      ans[cnt - 1]--;
      ans[cnt]++;
    }
  }
}

int main() {
  int N;

  while (cin >> H >> W >> N) {
    st.clear();
    memset(ans, 0, sizeof(ans));
    ans[0] = ((ll)H - 2) * ((ll)W - 2);
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      st.insert(P(a, b));
      calc(a, b);
    }
    for (int i = 0; i < 10; i++) {
      cout << ans[i] << endl;
    }
  }
}
