#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int N;
cin >> N;
vector<int> l(N),r(N);
int ans = 0;
for (int i = 0;i < N;i++) {
  cin >> l.at(i) >> r.at(i);
  ans += r.at(i) - l.at(i) + 1;
}
cout << ans << endl;


return 0;
}