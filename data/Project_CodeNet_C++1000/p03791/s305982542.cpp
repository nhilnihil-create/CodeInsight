#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const


template<typename... Types>
struct dynarr: std::vector<Types...> {
  using std::vector<Types...>::vector;
  using size_type = typename std::vector<Types...>::size_type;
  auto&& operator[](size_type i) { return this->at(i); }
  auto&& operator[](size_type i) const { return this->at(i); }
};

int main() {
  i64 N;
  cin >> N;
  dynarr<i64> x(N);
  rep(i,0,N) cin >> x[i];
  x[0] = 1;
  i64 cnt = 0;
  dynarr<i64> vec(N, 0);
  vec[0]++;
  rep(i,1,N) {
    vec[(cnt + 1) / 2]++;
    if(x[i] - x[i - 1] == 1) {
      cnt++;
    }
    else {
      x[i] = x[i - 1] + 2;
    }
  }
  i64 sum = 0;
  i64 mod = 1e9 + 7;
  i64 res = 1;
  rep(i,0,N) {
    sum += vec[i];
    res = (res * (sum - i)) % mod;
  }
  cout << res << endl;
}

