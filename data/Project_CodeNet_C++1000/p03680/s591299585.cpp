#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  int lighten = 1;
  vector<int> route;
  while (lighten != 2) {
    route.push_back(lighten);
    lighten = a.at(lighten - 1);
    if (route.size() > N) break;
  }
  if (route.size() > N) {
    cout << -1;
  }
  else {
    cout << route.size();
  }
}
