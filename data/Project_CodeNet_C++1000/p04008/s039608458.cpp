#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

vector<int> G[101010];


i64 ans = 0;
i64 N,K;

int dfs(int v,int f = -1){
  int cnt = 0;
  for(int to : G[v]){
    cnt = max(cnt , dfs(to,v) + 1);
  }
  if(f == -1) return 0;
  if(cnt == K - 1 && f != 0){
    ans++;
    cnt = -1;
  }
  return cnt;
}


int main(){
  cin >> N >> K;
  vector<int> a(N);
  rep(i,0,N - 1){
    cin >> a[i];
    a[i]--;
  }
  if(a[0] != 0) ans++;
  a[0] = 0;
  rep(i,1,N - 1){
    G[a[i]].push_back(i);
  }
  dfs(0);
  cout << ans << endl;
}
