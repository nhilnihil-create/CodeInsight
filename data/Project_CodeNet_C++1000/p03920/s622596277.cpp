#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  vector<bool> num(1);
  for (int i = 1; sum < N; i++) {
    sum += i;
    num.push_back(true);
  }
  num[sum - N] = false;
  for (int i = 1; i < num.size(); i++) if (num[i]) cout << i << endl;
}