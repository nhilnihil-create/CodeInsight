#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int,int> P;

int W,H;

bool used[200020];
int restx,resty;
P costs[200020];
int main(int argc, const char * argv[]) {
  scanf("%d%d", &W,&H);
  restx = W+1;
  resty = H+1;
  for(int i=0;i<W;++i) {
    int p;
    scanf("%d", &p);
    costs[i] = P(p, i);
  }
  for(int i=0;i<H;++i) {
    int q;
    scanf("%d", &q);
    costs[i+W] = P(q, i+W);
  }
  
  sort(costs, costs+W+H);
  
  long long answer = 0;
  for(int i=0;i<W+H;++i) {
    P cur = costs[i];
    int index = cur.second;
    if (index >= W) {
      answer += 1ll * cur.first * restx;
      resty--;
    } else {
      answer += 1ll * cur.first * resty;
      restx--;
    }
  }
  printf("%lld\n", answer);
  
  return 0;
}