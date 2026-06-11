#include <bits/stdc++.h>
using namespace std;

int A[100009];

int main() {
  int N, ans = 0; scanf("%d", &N);
  for(int i=1; i<=N; i++) scanf("%d",&A[i]);
  for(int i=1; i<=N; i++) if(A[i] == i) ++ans, ++i;
  printf("%d",ans);
}