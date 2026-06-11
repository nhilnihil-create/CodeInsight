#include <iostream>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];
ll diff [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  ll mn = 1e9 + 5;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mn = min(mn, arr[i]);
    sum += arr[i];
  }

  ll per_op = 0;
  for (int i = 1; i <= n; i++) {
    per_op += i;
  }

  if (sum % per_op != 0) {
    failure();
  }

  ll n_op = sum / per_op;
  
  for (int i = 0; i < n; i++) {
    diff[i] = arr[(i + 1) % n] - arr[i];
    diff[i] -= n_op;
    if (diff[i] % n != 0) {
      failure();
    }
    if (diff[i] > 0) {
      failure();
    }
  }

  cout << "YES" << endl;
}
