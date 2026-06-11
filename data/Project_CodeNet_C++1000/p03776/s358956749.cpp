#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cout << fixed << setprecision(15);

  int n, a, b;
  cin >> n >> a >> b;
  vector < ll > v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater < ll > ());
  ld sum = 0.0;
  for(int i = 0; i < a; i++){
    sum += (ld)v[i];
  }
  ld mean = sum / (ld)a;
  cout << mean << '\n';

  ll lst = v[a - 1], cnt = 0;
  for(int i = a; i < n; i++){
    if(v[i] == lst) cnt++;
  }

  int c = 0;
  for(int i = a - 1; i >= 0; i--){
    if(v[i] == lst) c++;
  }

  ll dp[55][55];

  dp[1][0] = dp[1][1] = 1;
  for(int i = 2; i < 51; i++){
    for(int j = 0; j <= i; j++){
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }

  ll ans;
  if(c == a){
    for(int i = a; i <= b && i <= cnt + c; i++){
      ans += dp[cnt + c][i];
    }
  }else{
    ans = dp[cnt + c][c];
  }

  cout << ans << '\n';
}
