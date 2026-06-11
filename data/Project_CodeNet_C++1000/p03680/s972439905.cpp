#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int count = 0;
  int i = 1;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  vector<int> store(0);

  while(i != 2) {
    store.push_back(i);
    i = vec[i - 1];
    if (find(store.begin(), store.end(), i) != store.end()) {
      count = -1;
      break;
    }
    count++;
  }

  cout << count << endl;
}