#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  int num[n];
  bool red[n];
  rep(i,n) {
    num[i]=1; red[i]=false;
  }
  red[0]=true;
  rep(i,m) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    num[x]--; num[y]++;
    if(red[x]) red[y]=true;
    if(num[x]==0) red[x]=false;
  }
  int ans=0;
  rep(i,n) {
    if(red[i]) ans++;
  }
  cout << ans << endl;
}
