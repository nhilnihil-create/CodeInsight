#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N, M; cin >> N >> M;
  vector<bool> dp(N,0);
  vector<int> ball(N,1);
  dp[0] = 1;

  int x, y;
  rep(i,M){
    cin >> x >> y;
    x--,y--;
    ball[x]--;
    ball[y]++;
    dp[y] = (dp[y] || dp[x]);
    if (ball[x]==0) dp[x] = false;
  }

  int cnt = 0;
  rep(i,N) if (dp[i]) cnt++;
  cout << cnt << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
