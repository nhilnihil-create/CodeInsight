// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  loop(i,0,n) cin >> A[i];
  int min_ = 100000000;
  for (int k=-100; k<=100; k++) {
    int cost = 0;
    for (auto &&a: A) cost += (a-k)*(a-k);
    min_ = min(cost, min_);
  }
  cout << min_ << endl;
  return 0;
}
