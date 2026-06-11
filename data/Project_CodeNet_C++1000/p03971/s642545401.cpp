#include<iostream>
#include<string>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int N, A, B; std::cin >> N >> A >> B;
  std::string S; std::cin >> S;
  int p = 0, op = 0;
  for(int i = 0; i < N; ++i) {
    bool pass;
    switch(S[i]) {
    case 'c': pass = false; break;
    case 'a': pass = (p < A+B); if(pass) ++p; break;
    default:  pass = (p < A+B && op < B); if(pass) ++p, ++op;
    }
    std::cout << (pass? "Yes\n": "No\n");
  }
  return 0;
}
