#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a = 1, b = 0, c;
  cin >> N;
  vector<int> vec(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> vec.at(i);
  while (true){
    if (vec.at(a) == 0){
      cout << -1 << endl;
      break;
    }
    if (vec.at(a) == 2){
      b++;
      cout << b << endl;
      break;
    }
    b++;
    c = a;
    a = vec.at(a);
    vec.at(c) = 0;
  }
}