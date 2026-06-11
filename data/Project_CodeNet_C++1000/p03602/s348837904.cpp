#include<bits/stdc++.h>
using namespace std;
int N;
int A[301][301];
bool B[301][301];
int main()
{
  int N; scanf("%d", &N);
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
  {
    scanf("%d", &A[i][j]);
    B[i][j] = true;
  }
  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j)
      for(int k=0; k<N; ++k)
      {
        if(i != j && j != k && k != i)
        {
          if(A[i][j]+A[j][k] < A[i][k])
          {
            puts("-1"); return 0;
          }
          else if(A[i][j] + A[j][k] == A[i][k])
            B[i][k] = false;
        }
      }
  long long ans = 0;
  for(int i=0; i<N; ++i)
    for(int j=0; j<i; ++j)
      if(B[i][j]) ans += A[i][j];
  printf("%lld\n", ans);
  return 0;
}