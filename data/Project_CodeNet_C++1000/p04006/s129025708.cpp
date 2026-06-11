#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define all(v) v.begin(), v.end()
#define lint long long
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail){
  std::cerr << " " << head;
  debug_impl(tail...);
}
#define debug(...)\
  std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
  debug_impl(__VA_ARGS__);\
  std::cerr << std::noboolalpha;

template <typename T>
std::istream& operator>> (std::istream& is, std::vector<T>& v) {
  for (auto & x : v) is >> x;
  return is;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
  auto n = v.size();
  os << "{";
  for (size_t i = 0; i < n; i++)
    {os << (i > 0 ? "," : "") << v.at(i);}
  return os << "}";
}

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n, x; std::cin >> n >> x;
  std::vector< int > a(n); std::cin >> a;
  lint ret = 1L << 60;
  rep(t, 0, n) {
    cmn(ret, std::accumulate(all(a), 0LL) + (lint)t * x);
    auto b = a;
    rep(i, 0, n) {
      auto j = (i > 0 ? i - 1 : n - 1);
      cmn(b.at(i), a.at(j));
    }
    std::swap(a, b);
  }
  std::cout << ret << std::endl;
  return 0;
}
