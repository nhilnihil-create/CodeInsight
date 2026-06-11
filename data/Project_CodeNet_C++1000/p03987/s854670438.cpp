#include<bits/stdc++.h>
using namespace std;
vector<int>parl;
vector<int>parr;
int rool(int v) {
  if (v == parl[v]) return v;
  return parl[v] = rool(parl[v]);
}
int roor(int v) {
  if (v == parr[v]) return v;
  return parr[v] = roor(parr[v]);
}
void unil(int a, int b) {
  a = rool(a);
  b = rool(b);
  if (a == b) return;
  if (a > b) swap(a, b);
  parl[b] = a;
}
void unir(int a, int b) {
  a = roor(a);
  b = roor(b);
  if (a == b) return;
  if (a > b) swap(a, b);
  parr[a] = b;
}
int main () {
  int N;
  cin >> N;
  vector<int>A(N);
  vector<int>B(N + 1);
  parl.resize(N);
  parr.resize(N);
  for (int i = 0; i < N; i ++) {
    cin >> A[i];
    B[A[i]] = i;
    parl[i] = i;
    parr[i] = i;
  }
  long long ans = 0;
  for (int i = N; i > 0; i --) {
    int v = B[i];
    long long l = (long long)v - rool(v) + 1;
    long long r = (long long)roor(v) - v + 1;
    long long j = (long long)i;
    //cout << i * l * r << endl;
    ans += (i * l * r);
    if (v > 0) unir(v, v - 1);
    if (v < N - 1) unil(v, v + 1);
  }
  cout << ans << endl;
}

