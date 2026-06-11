#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;

int main() {
  string s; cin>>s;
  int n=s.size();

  int ans=0;
  int gcnt=0;
  int pcnt=0;
  rep(i, n) {
    if (s[i]=='g'&&pcnt<gcnt) {
      pcnt++;
      ans++;
    }
    else if (s[i]=='g'&&pcnt>=gcnt) gcnt++;
    else if (s[i]=='p'&&pcnt<gcnt) pcnt++;
    else {
      gcnt++;
      ans--;
    }
  }
  cout<<ans<<endl;
  return 0;
}
