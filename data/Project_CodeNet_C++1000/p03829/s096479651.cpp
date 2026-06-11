#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long int a, b;
  cin >> n >> a >> b;
  vector<long long int> c(n);
  long long int cost = 0;
  for(int i=0;i<n;i++) cin >> c[i];
  for(int i=1;i<n;i++) {
    long long int distance = c[i] - c[i-1];
    cost += min(b, a * distance);
  }
  cout << cost << endl;
}