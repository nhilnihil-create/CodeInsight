#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int N, M, R; cin >> N >> M >> R;
  long D[N][N];
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) D[i][j] = (1L<<60);
  for (int i = 0; i < N; i++) D[i][i] = 0;
  int r[R]; for (int i = 0; i < R; i++) {cin >> r[i]; r[i]--;}
  for (int i =0 ; i < M; i++) {
    int a, b, c; cin >>a>>b>>c;a--;b--;
    D[a][b] = D[b][a] = c;
  }
  for (int k = 0; k < N; k++)
    for (int i =0;i<N;i++)
      for (int j=0;j<N;j++)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
  int perm[R]; for (int i = 0; i < R; i++) perm[i] = i;
  long min_sum = (1L<<60);
  do {
    long sum = 0;
    for (int i = 0; i < R-1; i++) sum += D[r[perm[i]]][r[perm[i+1]]];
    min_sum = min(min_sum, sum);
  } while (next_permutation(perm, perm+R));
  cout<<min_sum<<endl;
}