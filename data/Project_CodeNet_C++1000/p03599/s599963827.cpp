#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main() {
  int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  ll m = 0;
  vector<int> x(0), y(0);
  pair<int, int> data = make_pair(1, 0);
  for(int i = 0; i * A * 100 <= F; i++) {
    for(int j = 0; i * A * 100 + j * B * 100 <= F; j++) {
      if(i == 0 && j == 0) continue;
      x.push_back((i * A + j * B) * 100);
    }
  }
  for(int k = 0; k < x.size(); k++) {
    for(int i = 0; i * C + x[k] <= F; i++) {
      for(int j = 0; i * C + j * D + x[k] <= F; j++) {
        ll w = i * C + j * D;
        //cout << x[k] / 100 * E << " " << w << " " << i << " " << j << endl;
        m *= (w + x.at(k));
        if(x[k] / 100 * E >= w && chmax(m, w * data.first)) {
          //cout << "did";
          m /= data.first;
          data = make_pair(w + x.at(k), w);
        } else {
          m /= (w + x.at(k));
        }
      }
    }
  }
  if(data.first > 1) cout << data.first << " " << data.second << endl;
  else cout << 100 * A << " " << data.second << endl;
}