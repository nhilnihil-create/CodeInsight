#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> C(N + 1);
  
  for (int i = 1; i <= N; ++i) {
    int val = i;
    int count = 0;
    while (val % 2 == 0) {
      val /= 2;
      ++count;
    }
    C.at(i) = count;
  }
  
  int maxvalue = 0;
  int index = -1;
  for (int i = 1; i <= N; ++i) {
    maxvalue = max(C.at(i), maxvalue);
	if (C.at(i) >= maxvalue) {
      index = i;
    }
  }
  
  cout << index << endl;
  
}