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
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  write(args...);
}

int main() {
  string cur = "CODEFESTIVAL2016";
  string s; read(s);
  int ans = 0;
  for(int i = 0; i < s.length(); i++) {
    ans += s[i] != cur[i];
  }
  print(ans);
}