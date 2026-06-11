#include <bits/stdc++.h>
using namespace std;

int main() {
  int C, R;
  cin >> C >> R;
  vector<int> vec(2 * R);
  for (int i = 0; i < 2 * R; i++)
    cin >> vec.at(i);
  for (int i = 0; i < C; i++){
    int sum = 0;
    for (int j = 0; j < R; j++){
      if (vec.at(2 * j) == i + 1 || vec.at(2 * j + 1) == i + 1)
        sum++;
    }
    cout << sum << endl;
  }
}   
  