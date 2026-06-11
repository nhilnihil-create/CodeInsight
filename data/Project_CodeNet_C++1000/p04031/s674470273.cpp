#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  int n;
  cin >> n;
  int a[n];
  int max = -100, min = 100;
  for(int i = 0; i < n; i++) {cin >> a[i]; if (max < a[i]) max = a[i]; if (min > a[i]) min = a[i]; }
  int costmin = 100*100*100;
  int cost = 0;
  for (int i = min; i <= max; i++) {
    for (int j = 0; j < n; j++) {
      cost += (a[j]-i) * (a[j]-i);
    }
    if (costmin > cost) costmin = cost;
    cost = 0;
  }
  cout << costmin << endl;
}