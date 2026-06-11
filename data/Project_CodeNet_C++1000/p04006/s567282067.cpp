#include <bits/stdc++.h>
using namespace std;

#define INF 102030405060708090

// memo: 2^17 == 131072
const int MAX_N = 1 << 17; 
int n2 = 1;

vector<int> dat(MAX_N*2-1);

void init(int m) {
  while (n2 < m) n2 *= 2;

  for (int i=0;i<n2*2-1;i++) {
    dat[i] = INT_MAX;
  }
}

void update(int k, int a) {
  k += n2-1;
  dat[k] = a;
  while (k > 0) {
    k = (k-1)/2;
    dat[k] = min(dat[k*2+1],dat[k*2+2]);
  }
}

// min of [a,b)
// usage : query(a,b,0,0,n2);
int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return INT_MAX;
  if (a <= l && r <= b) return dat[k];
  else {
    int vl = query(a,b,k*2+1,l,(l+r)/2);
    int vr = query(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr);
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i=0;i<n;i++) cin >> a[i];

  init(n*2);
  for (int i=0;i<n;i++) {
    update(i,a[i]);
    update(n+i,a[i]);
  }

  long long ans = INF;
  for (int i=0;i<n;i++) {
    long long kans = x*i;
    for (int j=0;j<n;j++) {
      kans += query(n+j-i,n+j+1,0,0,n2);
    }
    ans = min(ans,kans);
  }
  cout << ans << endl;
}