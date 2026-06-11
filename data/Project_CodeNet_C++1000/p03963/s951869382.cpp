#include <bits/stdc++.h>
using namespace std;

int main() {
  long ball_num, color_val;
  cin >> ball_num >> color_val;

  cout << (long)(color_val * pow(color_val-1, ball_num-1)) << endl;
}