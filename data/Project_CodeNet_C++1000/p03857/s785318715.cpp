#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int NMAX = 200000;
const ll P = 1e9+7;
int car_uf[NMAX+1];
int train_uf[NMAX+1];
int car_root[NMAX+1];
int train_root[NMAX+1];
void uf_init(int uf[]) {
  for(int i=0; i<=NMAX; i++) uf[i] = i;
}
int uf_root(int uf[], int x) {
  if(uf[x]==x) return x;
  return uf[x] = uf_root(uf, uf[x]);
}
void uf_unite(int uf[], int a, int b) {
  a = uf_root(uf, a);
  b = uf_root(uf, b);
  if(a==b) return;
  uf[a] = b;
}
void print_uf(int uf[], int n) {
  for(int i=1; i<=n; i++) {
    if(i==1) {
      cout << uf[i];
    } else {
      cout << " " << uf[i];
    }
  }
  cout << endl;
}
int main() {
  uf_init(car_uf);
  uf_init(train_uf);
  int n,k,l;
  cin >> n >> k >> l;
  for(int i=0; i<k; i++) {
    int p,q;
    cin >> p >> q;
    uf_unite(car_uf, p, q);
  }
  for(int i=0; i<l; i++) {
    int r,s;
    cin >> r >> s;
    uf_unite(train_uf, r,s);
  }
  for(int i=1; i<=n; i++) {
    car_root[i]=uf_root(car_uf, i);
    train_root[i]=uf_root(train_uf, i);
  }
  map<ll, int> m;
  for(int i=1; i<=n; i++) {
    ll k = car_root[i]*P+train_root[i];
    auto it = m.find(k);
    if(it!=m.end()) {
      m[k]++;
    } else {
      m[k]=1;
    }
  }
  for(int i=1; i<=n; i++) {
    ll k = car_root[i]*P+train_root[i];
    if(i==1) {
      cout << m[k];
    } else {
      cout << " " << m[k];
    }
  }
  cout << endl;
  return 0;
}
