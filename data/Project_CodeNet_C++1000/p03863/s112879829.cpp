#include<iostream>
#include<string>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  std::string s; std::cin >> s;
  int l = (s.front()==s.back())? 3: 2;
  int t = (s.size()-l)%2;
  if(t==1) fin("First");
  fin("Second");
  return 0;
}