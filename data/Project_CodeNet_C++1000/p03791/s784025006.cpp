#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

const int mod = 1e9 + 7;

int main()
{
  int N, X[100001];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X[i];
  }

  int64 ret = 1;
  int lastidx = 0;
  for(int i = 1; i < N; i++) {
    ret *= (i - lastidx + 1);
    ret %= mod;
    while((i - lastidx) * 2 + 1 > X[i]) ++lastidx;
  }
  cout << ret << endl;
}