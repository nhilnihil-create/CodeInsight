#include <bits/stdc++.h>
using namespace std;

int main() {
  int q_num, total_time = 0;
  cin >> q_num;
  vector<int> time(q_num);

  for(int i=0; i < q_num; i++) {
    cin >> time[i];
    total_time += time[i];
  }

  int drink_type;
  cin >> drink_type;
  vector<int> ans(drink_type);

  for(int i = 0; i < drink_type; i++) {
    int p, x;
    cin >> p >> x;
    ans[i] = total_time + (x - time[p-1]);
  }

  for(int a : ans) cout << a << endl;
}