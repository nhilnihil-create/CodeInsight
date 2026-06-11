#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  int mp[19];
  mp[1]=mp[3]=mp[5]=mp[7]=mp[8]=mp[10]=mp[12]=1;
  mp[4]=mp[6]=mp[9]=mp[11]=2;
  mp[2]=3;
  int x,y;
  cin>>x>>y;
  if(mp[x]==mp[y])puts("Yes");
  else puts("No");
  return(0);
}
