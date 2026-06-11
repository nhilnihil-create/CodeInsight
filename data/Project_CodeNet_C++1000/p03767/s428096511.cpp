#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int N;
  cin >> N;
  int a[3*N];
  rep(i, 3*N){
    cin >> a[i];
  }
  sort(a, a + 3*N, greater<int>());
  
  long long sum = 0;
  rep(i, N){
    sum += a[2*i + 1];
  }
  cout << sum << endl;
}
