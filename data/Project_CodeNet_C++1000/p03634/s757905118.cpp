#include <bits/stdc++.h>
using namespace std;

long n,a,b,c,q,k,x,y;
vector<vector<long>> aaa(100010);
vector<long> bbb(100010,-1);
vector<long> ans(100010);

void tansaku(long x,long y) {
  bbb[x-1]=y;
  for(long i=0;i<aaa[x-1].size();i++) {
    if(bbb[aaa[x-1][i]/10000000000-1]==-1) tansaku(aaa[x-1][i]/10000000000,y+aaa[x-1][i]%10000000000);
  }
}

int main() {
  cin >> n;
  for(long i=0;i<n-1;i++) {
    cin >> a >> b >> c;
    aaa[a-1].push_back(b*10000000000+c);
    aaa[b-1].push_back(a*10000000000+c);
  }
  cin >> q >> k;

  tansaku(k,0);
  for(long i=0;i<q;i++) {
    cin >> x >> y;
    ans[i]=bbb[x-1]+bbb[y-1];
  }

  for(long i=0;i<q;i++) cout << ans[i] << endl;
}