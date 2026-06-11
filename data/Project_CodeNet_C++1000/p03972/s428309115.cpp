#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;
typedef pair<int, bool> Data;
typedef pair<LLI, Data> Event;

int W;
int H;
LLI ls[2];
LLI cnt[2];
LLI ps[114514];
LLI qs[114514];
vector<Event> es;

int main() {
  scanf("%d%d", &H, &W);
  ls[0] = H;
  ls[1] = W;

  for (int i=0; i<H; i++) {
    scanf("%lld", &ps[i]);
    es.emplace_back(Event(ps[i], Data(i, 0)));
  }

  for (int i=0; i<W; i++) {
    scanf("%lld", &qs[i]);
    es.emplace_back(Event(qs[i], Data(i, 1)));
  }

  sort(es.begin(), es.end());

  LLI ans = 0;
  for (auto &e : es) {
    LLI cost = e.first;
    int idx = e.second.first;
    int k = e.second.second;

    ans += cost * (ls[1^k]+1 - cnt[1^k]);
    cnt[k]++;
  }
  printf("%lld\n", ans);
}
