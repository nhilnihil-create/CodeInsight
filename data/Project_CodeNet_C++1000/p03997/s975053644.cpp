#include <bits/stdc++.h>
using namespace std;

int menseki(int a, int b, int h) {
  int answer = 0;
  answer = (a + b) * h / 2;
  return answer;
}

int main() {
  int a, b, h;
  cin >> a >> b >> h;
  cout << menseki(a, b, h) << endl;
}