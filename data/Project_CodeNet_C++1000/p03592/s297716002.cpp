#include <cstdio>
using namespace std;
int N, M, K;
int main() {
  scanf("%d %d %d", &N, &M, &K);
  bool ok = false;
  for(int i= 1; i <= N; ++i) {
    int on = i*M, diff = N-2*i;
    for(int j = 0; j <= M; ++j) {
      if(on+diff*j != K) continue;
      ok = true;
      break;
    }
  }
  printf("%s\n", (ok?"Yes":"No"));
}