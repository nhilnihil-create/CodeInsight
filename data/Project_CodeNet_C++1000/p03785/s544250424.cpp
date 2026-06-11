#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

int main(){
  ll n,c,k;
  cin >> n >> c >> k;
  vector<ll> t(n);

  rep(i,n){
    cin >> t.at(i);
  }

  sort(all(t));

  ll ans = 0,time = t.at(0),count = 1;

  for(int i=1;i<n;i++){
    count++;
    if(t.at(i)>time+k || count > c){
      time=t.at(i);
      count=1;
      ans++;
    }
  }

  if(count) ans++;

  cout << ans << endl;
}
