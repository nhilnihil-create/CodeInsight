#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;

const int MOD=1000000007;

int main() {
  int n; cin>>n;
  string s1,s2; cin>>s1>>s2;
  vector<bool> num;
  int r=0;
  while (r < n) {
    if(s1[r]==s2[r]) {
      num.push_back(true);
	  r++;
	} else {
	  num.push_back(false);
	  r+=2;
	}
  }
  ll ans=3;
  rep(i, num.size()) {
    if (i == 0) {
      if(!num[i]) ans = 6;
      continue;
	}
	if (num[i]&&num[i-1]) ans*=2;
    else if (num[i]&&!num[i-1]) ans*=1;
    else if (!num[i]&&num[i-1]) ans*=2;
	else if (!num[i]&&!num[i-1]) ans*=3;
	ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}
