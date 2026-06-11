#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<int>a(N);
  vector<int>count(100001,0);
  vector<int>ans(99999);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    count.at(a.at(i))++;
  }
  
  for (int i = 0; i < 99999; i++) {
    ans.at(i) = count.at(i) + count.at(i+1) + count.at(i+2);
  }
  sort(ans.begin(), ans.end());
  
  cout << ans.at(99998) << endl;
}
  