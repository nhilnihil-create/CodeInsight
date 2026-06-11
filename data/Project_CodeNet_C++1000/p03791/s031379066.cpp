#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int p[100010];

int main(){
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", &p[i]);

  p[1] = 1; for(int i = 2; i <= N; i++) p[i] = min(p[i], p[i - 1] + 2);

  int ans = 1; bool prev = false; int rem = 0;

  for(int i = 1; i < N; i++){
    if(p[i] + 1 == p[i + 1]){
      if(prev) prev = false;
      else{
        ans = 1LL * ans * (i + 1 - rem) % MOD;
        rem++; prev = true;
      }
    }
  }

  for(int i = 1; i <= N - rem; i++){
    ans = 1LL * ans * i % MOD;
  }

  printf("%d\n", ans);
  return 0;
}
