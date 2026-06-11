#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define all(v) v.begin(), v.end()
#define lint long long
auto cmn = [](auto& a, auto c){if (a > c) {a = c; return true;} return false;};
auto cmx = [](auto& a, auto c){if (a < c) {a = c; return true;} return false;};
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
  int n, k; std::cin >> n >> k;
  std::vector< int > a(n); std::cin >> a;
  std::vector< int > b(n, 0), c(n, 0);
  rep(i, 0, n) {
    auto crr = a.at(i);
    if (crr > 0) b.at(i) = crr;
    else         c.at(i) = -crr;
  }
  lint sum = std::accumulate(all(b), 0LL);
  auto ret = 0LL;
  auto plus  = std::accumulate(b.begin(), b.begin() + k, 0LL);
  auto minus = std::accumulate(c.begin(), c.begin() + k, 0LL);
  rep(r, k, n + 1) {
    auto l = r - k;
    cmx(ret, sum - plus);
    cmx(ret, sum - minus);
    if (r == n) break;
    plus  += b.at(r);
    plus  -= b.at(l);
    minus += c.at(r);
    minus -= c.at(l);
  }
  std::cout << ret << std::endl;
  return 0;
}