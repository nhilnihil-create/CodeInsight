#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double getTime() { 
  return clock() / (double) CLOCKS_PER_SEC;
}

void read() {};

template<typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}

void write() {};

template <typename T, typename... Args>
void write(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  write(args...);
}

int main() {
  string s; read(s);
  write(s.substr(0, 4), s.substr(4));
}