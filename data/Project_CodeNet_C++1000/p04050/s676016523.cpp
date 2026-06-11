#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int N, M; cin >> N >> M;
  vi arr(M);
  rep(i,M) cin >> arr[i];

  if (M == 1) {
    cout << arr[0] << endl;
    if (arr[0] == 1) {
      cout << 1 << endl;
      cout << arr[0] << endl;
    } else {
      cout << 2 << endl;
      cout << 1 << ' ' << arr[0]-1 << endl;
    }
    return 0;
  }

  vi odd;
  rep(i,M) if (arr[i]%2) odd.push_back(i);

  if (odd.size() > 2) {
    cout << "Impossible" << endl;
    return 0;
  }

  if (odd.size() != 0) swap(arr[0], arr[odd[0]]);
  if (odd.size() == 2) swap(arr[M-1], arr[odd[1]]);

  rep(i,M-1) cout << arr[i] << ' ';
  cout << arr[M-1] << endl;

  ++arr[0]; --arr[M-1];
  if (arr[M-1] == 0) {
    arr.pop_back();
    --M;
  }

  cout << M << endl;

  rep(i,M-1) cout << arr[i] << ' ';
  cout << arr[M-1] << endl;
  return 0;
}
