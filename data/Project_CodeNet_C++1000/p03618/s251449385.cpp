#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  string s;cin>>s;
  vector<ll> c(26);
  rep(i, s.size()) c[s[i]-'a']++;

  ll result = s.size()*(s.size()+1)/2+1;
  rep(i, 26)result -= (c[i]*(c[i]-1)/2);
  cout<<result-s.size();

  return 0;
}