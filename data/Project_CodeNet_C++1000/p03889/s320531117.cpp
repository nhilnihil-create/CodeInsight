#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
string bpqd = "bpqd";
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
  string S;
  cin >> S;
  string ans = "Yes";
  for(int i = 0; i < S.size(); i++) {
    for(int j = 0; j < 4; j++) {
      if(S[i] == bpqd[j]) {
        if(S[S.size() - 1 - i] != bpqd[3-j]) ans = "No";
      }
    }
  }
  cout << ans;
    return 0;
}