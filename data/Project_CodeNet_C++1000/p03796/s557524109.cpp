#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

long N, answer = 1;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  long divide_num = 1;
  for (int i = 0; i < 9; i++) {
    divide_num *= 10;
  }
  divide_num += 7;

  for (int i = 1; i <= N; i++) {
    answer *= i;
    answer %= divide_num;
  }
  cout << answer << endl;
}