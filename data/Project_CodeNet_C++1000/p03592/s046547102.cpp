#include <cstdio>
using namespace std;
int N, M, K;
int main() {
  scanf("%d %d %d", &N, &M, &K);
  int k[N*M+1] = {0};
  for(int i= 1; i <= N; ++i) {
    int on = i*M, diff = N-2*i;
    for(int j = 0; j <= M; ++j) {
      k[on+diff*j] = 1;
    }
  }
  printf("%s\n", (k[K]>0?"Yes":"No"));
}