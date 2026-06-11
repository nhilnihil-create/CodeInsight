#include <bits/stdc++.h>
using namespace std;


int main() {
  long long N, mod = 1e9+7, total = 1;
  cin >> N;
  for(int i = 1; i <= N; i++){
    total *= i;
    total = total % mod;
  }
  cout << total << endl;
}
