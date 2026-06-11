#include <bits/stdc++.h>
using namespace std;

long n,m,r,ans=10000000000;
vector<long> x(8),a(100000),b(100000),c(100000);
vector<vector<long>> w(200,vector<long>(200,10000000000));

void saiki(vector<long> v,set<long> vv) {
  if(v.size()==r) {
    long aaa=0;
    for(long i=0;i<r-1;i++) {
      aaa+=w[v[i]-1][v[i+1]-1];
    }
    ans=min(aaa,ans);
  } else {
    for(long i=0;i<r;i++) {
      if(vv.find(x[i])==vv.end()) {
        vector<long> nv=v;
        nv.push_back(x[i]);
        set<long> nvv=vv;
        nvv.insert(x[i]);
        saiki(nv,nvv);
      }
    }
  }
  return;
}

int main() {
  cin >> n >> m >> r;
  for(long i=0;i<r;i++) cin >> x[i];
  for(long i=0;i<m;i++) cin >> a[i] >> b[i] >> c[i];

  for(long i=0;i<m;i++) {
    w[a[i]-1][b[i]-1]=c[i];
    w[b[i]-1][a[i]-1]=c[i];
  }
  for(long i=0;i<n;i++) w[i][i]=0;
  for(long k=0;k<n;k++) {
    for(long i=0;i<n;i++) {
      for(long j=0;j<n;j++) w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
    }
  }

  saiki({},{});
  cout << ans << endl;
}