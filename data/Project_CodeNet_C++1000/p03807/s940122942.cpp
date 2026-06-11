#include <cstdio>
#include <cctype>
using namespace std;
template <typename T> inline void read(T& ret) {
  int c = getchar(); ret = 0;
  while(!isdigit(c)) { c = getchar(); }
  while(isdigit(c)) { ret = ret * 10 + c - 48, c = getchar(); }
}
template <typename T, typename... Args> inline void read(T& ret, Args&... args) { read(ret), read(args...); }
int main() {
  int n; read(n); int sum = 0;
  while(n --) {
    int i; read(i);
    sum += i & 1;
  }
  printf("%s\n", sum & 1 ? "NO" : "YES");
  return 0;
}
