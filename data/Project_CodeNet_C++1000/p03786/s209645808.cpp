# include <bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
  int n;
  cin >> n;

  ll creatures[100005], sum[100005];
  for(int i=1; i<=n; i++){
    cin >> creatures[i];
  }

  sort(creatures+1, creatures+n+1);
  creatures[n+1] = 0;
  sum[0] = 0;
  for(int i=1; i<=n; i++) sum[i] = sum[i-1] + creatures[i];

  int ans = 0;
  for(int i=n; i>=1; i--){
    if(sum[i]*2 < creatures[i+1]){
      break;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}