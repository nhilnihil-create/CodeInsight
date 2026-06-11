#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll n, l, t;
  ll p = 1;
  cin >> n >> l >> t;
  int pla[100100];
  for(int i = 1; i <= n; i++) {
    int x , w;
    cin >> x >> w;
    if(w==1) {
      pla[i] = (x+t)%l;
      p += (x+t)/l;
    }
    else {
      pla[i] = (x-t)%l;
      p += (x-t)/l;
    }
    if(pla[i]<0) {
      pla[i] += l;
      p--;
    }
  }
  sort(pla+1, pla+n+1);
  p = (p%n+n)%n;
  if(p==0) p = n;
  for(int i = p; i <= n; i++) cout << pla[i] << endl;
  for(int i = 1; i <= p-1; i++) cout << pla[i] << endl;
  return 0;
}