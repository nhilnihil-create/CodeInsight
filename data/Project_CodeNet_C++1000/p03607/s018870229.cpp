#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, bool> numbers;
  for (int i = 0; i < N; i++) {
    int number = 0;
    cin >> number;
    numbers[number] = !numbers[number];
  }

  int count = 0;
  for (auto itr = numbers.begin(); itr != numbers.end(); itr++) {
    if (itr->second == true) count++;
  }

  cout << count << endl;
}
