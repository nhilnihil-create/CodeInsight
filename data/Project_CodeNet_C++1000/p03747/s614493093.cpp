#include<bits/stdc++.h>
using namespace std;

struct Ant {int x, w, y, z=-1;};

int main() {
  int N, L, T;
  cin >> N >> L >> T;
  vector<Ant> ant(N);
  for(auto& a: ant) cin >> a.x >> a.w;

  for(auto& a: ant) {
    if(a.w == 1) a.y = (a.x + T) % L;
    else         a.y = (a.x - T) % L;
    if(a.y < 0) a.y += L;
  }

  ant[0].z = 0;
  for(auto& a: ant) if(a.w != ant[0].w) {
    if(ant[0].w == 1) {
      auto d = a.x - ant[0].x;
      if(d <= 2*T) ant[0].z += 1 + (2*T-d)/L;
    } else {
      auto d = ant[0].x + L-a.x;
      if(d <= 2*T) ant[0].z -= 1 + (2*T-d)/L;
    }
    ant[0].z %= N;
    if(ant[0].z < 0) ant[0].z += N;
  }

  auto s = ant[0];
  sort(begin(ant), end(ant), [](auto l, auto r) {return l.y!=r.y ? l.y<r.y : l.w>r.w;});

  for(auto i=0; i<N; ++i) if(ant[i].x == s.x) {
    for(auto j=0; j<N; ++j) {
      auto p = (i + j) % N;
      auto z = (s.z + j) % N;
      ant[p].z = z;
    }
    break;
  }

  sort(begin(ant), end(ant), [](auto l, auto r) {return l.z < r.z;});
  for(auto a: ant) cout << a.y << endl;
}
