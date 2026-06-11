#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  ll ans = 0;
  vector<ll> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  int i = 0;
  while (i < N) {
    while (i < N-1 && arr[i] == arr[i+1]) {
      i++;
    }
    if (i < N-1 && arr[i] < arr[i+1]) {
      while (i < N-1 && arr[i] <= arr[i+1]) {
        i++;
      }
    }
    else if (i < N-1 && arr[i] > arr[i+1]) {
      while (i < N-1 && arr[i] >= arr[i+1]) {
        i++;
      }
    }
    ans++;
    i++;
  }
  cout << ans << endl;
}
