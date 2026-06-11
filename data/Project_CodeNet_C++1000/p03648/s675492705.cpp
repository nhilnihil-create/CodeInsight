#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K, sv[66], ans[66];

const int N = 50;

int main(){

  cin >> K;

  ll div = K/N, lft = K%N;

  for(int i = 0; i < N; i++)sv[i] = div + (i < lft);

  for(int i = 0; i < N; i++){

    ll sum = 0;

    for(int j = 0; j < N; j++)if(i != j)sum += sv[j];

    ans[i] = N * (sv[i] + 1) - sum - 1;

  }

  cout << N << '\n';

  for(int i = 0; i < N; i++)
    cout << (i ? " " : "") << ans[i];

  puts("");





}
