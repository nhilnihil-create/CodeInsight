#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(20);
  int N, A, B;
  cin >> N >> A >> B;
  vector<long long> v(N);
  for (int i = 0; i < N; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long mx_sum = 0;
  int mx_cnt = 1;
  for (int i = A; i <= B; i++){
    long long sum = 0;
    for (int j = 0; j < i; j++){
      sum += v[N - 1 - j];
    }
    if (sum * mx_cnt > mx_sum * i){
      mx_sum = sum;
      mx_cnt = i;
    }
  }
  cout << (double) mx_sum / mx_cnt << endl;
  vector<vector<long long>> binom(51, vector<long long>(51));
  for (int i = 0; i < 51; i++){
    binom[i][0] = 1;
    binom[i][i] = 1;
  }
  for (int i = 2; i < 51; i++){
    for (int j = 1; j < i; j++){
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
  }
  long long ans = 0;
  for (int i = A; i <= B; i++){
    long long sum = 0;
    for (int j = 0; j < i; j++){
      sum += v[N - 1 - j];
    }
    if (sum * mx_cnt == mx_sum * i){
      long long last = v[N - i];
      int a = lower_bound(v.begin(), v.end(), last) - v.begin();
      int b = upper_bound(v.begin(), v.end(), last) - v.begin();
      ans += binom[b - a][N - i - a];
    }
  }
  cout << ans << endl;
}