#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  ll l=s.length();
  map<ll,ll> mp;rep(i,l) mp[s[i]-'a']++;
  ll ans=l*(l-1)/2;
  for(auto e:mp) ans-=e.second*(e.second-1)/2;
  print(ans+1);
  return 0;
}