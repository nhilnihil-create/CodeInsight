#include<iostream>
#include<string>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  std::string S; std::cin >> S;
  auto calc = [](auto&& f, std::string s)->int64_t {
    if(s.size()==1) return s[0]-'0';
    int64_t res = std::atol(s.c_str());
    for(int i = 1; i < s.size(); ++i) {
      std::string l=s.substr(0, i), r=s.substr(i);
      res += std::atol(l.c_str()) << r.size()-1;
      res += f(f, r);
    }
    return res;
  };
  fin(calc(calc,S));
  return 0;
}
