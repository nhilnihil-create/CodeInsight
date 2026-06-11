#include <iostream>
#include <string>

int N;
std::string s, t;

int main() {
  std::cin >> N >> s >> t;
  for (int i = N; i >= 0; --i)
    if (s.substr(N - i) == t.substr(0, i))
      return std::cout << N + N - i, 0;
}