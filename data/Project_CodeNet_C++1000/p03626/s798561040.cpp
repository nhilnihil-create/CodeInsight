#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;
const ll mod = 1e9+7;

int n;
string s[2];
ll dp[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n;
  cin>>s[0]>>s[1];
  if (s[0][0]==s[1][0]) {
    dp[0] = 3;
  } else {
    dp[0] = 6;
  }

  for (int i=1; i<n; i++) {
    // continuing =
    if (s[0][i]==s[0][i-1] && s[1][i]==s[1][i-1]) {
      dp[i]=dp[i-1];
      continue;
    }
    // vertical |
    if (s[0][i]==s[1][i]) {
      if (s[0][i-1]==s[1][i-1]) {
	dp[i]=2LL*dp[i-1];
	dp[i]%=mod;
      } else {
	dp[i]=dp[i-1];
      }
    } else {
      // starting =
      if (s[0][i-1]==s[1][i-1]) {
	dp[i]=2LL*dp[i-1];
      } else {
	dp[i]=3LL*dp[i-1];
      }
      dp[i]%=mod;
    }
  }

  cout<<dp[n-1]<<endl;
  

  return 0;
}
