#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

template<class K, class V>
vector<V> values(map<K, V> const& m) {
  vector<V> result;
  for (auto e: m) result.push_back(e.second);
  return result;
}

template<class T>
vector<T> grep(std::function<bool(T)> const& f, vector<T> const& v) {
  vector<T> result;
  for (auto e: v) if (f(e)) { result.push_back(e); }
  return result;
}

int main() {
  int H, W; cin >> H >> W;
  map<char, int> mp;
  rep(i, H * W) {
    char ch; cin >> ch;
    mp[ch]++;
  }
  auto vs = values(mp);

  if (H == 1 || W == 1) {
    auto len = max(H, W);
    if (len % 2 == 0 &&
        grep<int>([](int n){ return n % 2 == 0; }, vs).size() == vs.size()) {
      cout << "Yes\n";
    }
    else if (len % 2 &&
        grep<int>([](int n){ return n % 2 == 0; }, vs).size() == vs.size() - 1) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
    return 0;
  }

  if (grep<int>([](int n){ return n % 4 == 0; }, vs).size() == vs.size()) {
    cout << "Yes\n";
    return 0;
  }

  int even_limit = 0;
  if (H % 2) even_limit += W / 2;
  if (W % 2) even_limit += H / 2;

  int odd_limit = 0;
  if ((H % 2) && (W % 2)) odd_limit = 1;

  int even_cnt = 0, odd_cnt = 0;
  for (auto e: vs) {
    if (e % 4 == 0) continue;
    if (e % 2 == 0) even_cnt++;
    else odd_cnt++;
  }
  if (even_cnt <= even_limit && odd_cnt <= odd_limit) {
    cout << "Yes\n";
    return 0;
  }

//  cout << even_cnt << " " << even_limit << ", " << odd_cnt << " " << odd_limit << "\n";
  cout << "No\n";
}
