#include <bits/stdc++.h>
using namespace std;

long n,w,w1,a,b,ans=0;
vector<vector<long>> p(4,vector<long>(0));

void saiki(long ii,long aaa,long bbb) {
  if(ii==4) {
    ans=max(ans,aaa);
    return;
  }
  saiki(ii+1,aaa,bbb);
  for(long i=0;i<p[ii].size();i++) {
    if((w1+ii)*(i+1)+bbb>w) break;
    saiki(ii+1,aaa+p[ii][i],bbb+(w1+ii)*(i+1));
  }
  return;
}

int main() {
  cin >> n >> w;
  cin >> w1 >> b;
  p[0].push_back(b);
  for(long i=1;i<n;i++) {
    cin >> a >> b;
    p[a-w1].push_back(b);
  }
  for(long i=0;i<4;i++){
    sort(p[i].begin(),p[i].end());
    reverse(p[i].begin(),p[i].end());
    for(long j=1;j<p[i].size();j++) {
      p[i][j]=p[i][j-1]+p[i][j];
    }
  }
  saiki(0,0,0);
  cout << ans << endl;
}