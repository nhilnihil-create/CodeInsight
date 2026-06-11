#include <iostream>
#include <vector>

#define ll long long
#define LINF LLONG_MAX

using namespace std;

int main() {
  string s;
  int K;
  cin >> s >> K;
  int size = s.size();
  for (int i = 0; i < size; i++) {
    int index = 26 - (s[i] - 'a');
    if (s[i] == 'a') {
      continue;
    }
    if (index <= K) {
      s[i] = 'a';
      K = K - index;
    }
  }
  s[size - 1] = char(s[size - 1] + (K % 26));
  cout << s << endl;
}