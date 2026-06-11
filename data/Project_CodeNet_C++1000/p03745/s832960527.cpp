#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> numbers(N);
  for (int i = 0; i < N; i++) cin >> numbers.at(i);

  int chain_count = 0;

  for (int i = 0; i < N; i++) {
    // 同値を skip
    while (i + 1 < N && numbers.at(i) == numbers.at(i + 1)) i++;

    if (i + 1 < N && numbers.at(i) < numbers.at(i + 1)) {
      // 増加している間は同値を skip
      while (i + 1 < N && numbers.at(i) <= numbers.at(i + 1)) i++;

    } else if (i + 1 < N && numbers.at(i) > numbers.at(i + 1)) {
      // 減少している間は同値を skip
      while (i + 1 < N && numbers.at(i) >= numbers.at(i + 1)) i++;
    }

    chain_count++;
  }

  cout << chain_count << endl;
}