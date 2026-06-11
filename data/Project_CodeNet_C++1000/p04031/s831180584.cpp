#include <bits/stdc++.h>
using namespace std;
/*
{a_i}をsortし、a_iのとり得る値の範囲の中でfor
和の最小が答え
*/

int main() {

  int N;
  cin >> N;
  vector<int> a(N);
  int ans = 5000000;

  for (int x = 0 ; x < a.size(); x++) {
    cin >> a.at(x);
  }

  sort(a.begin(),a.end());
  int k = a.at(N-1) - a.at(0) + 1;
  vector<int> min(k);
  k = 0;
  for (int j = a.at(0); j <= a.at(N-1); j++) {
    for (int i = 0; i < N; i++) {
      min.at(k) += (a.at(i)-j)*(a.at(i)-j);
    }
    k++;
  }

  sort(min.begin(),min.end());


  cout << min.at(0) << endl;

}
