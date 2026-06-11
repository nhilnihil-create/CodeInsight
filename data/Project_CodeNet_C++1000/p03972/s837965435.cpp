#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h;
  cin>>w>>h;
  long long p[w], q[h];
  for (int i=0; i<w; i++) cin>>p[i];
  for (int i=0; i<h; i++) cin>>q[i];

  sort(p, p + w);
  sort(q, q + h);

  int i = 0, j = 0;
  long long cost = 0;
  while (i < w && j < h) {
    if (p[i] < q[j]) {
      cost += p[i] * (h + 1 - j);
      ++i;
    } else {
      cost += q[j] * (w + 1 - i);
      ++j;
    }
  }
  while (i < w) {
    cost += p[i] * (h + 1 - j);
    ++i;
  }
  while (j < h) {
    cost += q[j] * (w + 1 - i);
    ++j;
  }
  cout<<cost<<endl;
}