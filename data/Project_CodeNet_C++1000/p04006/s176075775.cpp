#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
struct segment_tree{
  int N;
  vector<long long> ST;
  segment_tree(vector<long long> &A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<long long>(N * 2 - 1, INF);
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  long long query(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return INF;
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return min(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
    }
  }
  long long query(int L, int R){
    return query(L, R, 0, 0, N);
  }
};
int main(){
  int N;
  long long x;
  cin >> N >> x;
  vector<long long> a(N * 2);
  for (int i = 0; i < N; i++){
    cin >> a[i];
    a[N + i] = a[i];
  }
  segment_tree ST(a);
  long long ans = INF;
  for (int i = 0; i < N; i++){
    long long tmp = x * i;
    for (int j = 0; j < N; j++){
      tmp += ST.query(j, j + i + 1);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}