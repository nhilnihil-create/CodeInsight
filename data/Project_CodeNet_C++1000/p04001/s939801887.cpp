#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  unsigned long long int sum = 0;
  int N = (int)s.size();
  for (int tmp = 0; tmp < (1 << N-1); tmp++) {
    bitset<10> a(tmp);
    long x = 0;
    long buf = 0;
    for (int i = 0; i < N; i++) {
      x = x*10 + (s.at(i) - '0');
      if (a.test(i) || i == N-1) {
        buf += x;
        x = 0;
      }
    }
    sum += buf;
  }
  
  cout << sum << endl;
}