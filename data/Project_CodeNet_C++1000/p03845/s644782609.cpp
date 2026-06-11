#include <bits/stdc++.h>
using namespace std;

int main() {
  int q_num, total_time = 0;
  cin >> q_num;
  vector<int> t(q_num);

  for(int i=0; i < q_num; i++) {
    cin >> t[i];
    total_time += t[i];
  }

  int drink_type;
  cin >> drink_type;
  vector<int> t_t(drink_type, total_time);

  for(int i=0; i < drink_type; i++) {
    int P, X;
    cin >> P >> X;
    t_t[i] += X - t[P-1];
  }

  for(int i=0; i < drink_type; i++) {
    cout << t_t[i] << endl;
  }
}

