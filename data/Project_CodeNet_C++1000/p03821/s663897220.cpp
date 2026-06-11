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
  int n; cin >> n;
  vector<ll> a(n),b(n);

  rep(i,n)  cin >> a.at(i) >> b.at(i);
  ll ans = 0;

  for(int i=n-1;i>=0;i--){
    if((a.at(i)+ans)%b.at(i))ans += b.at(i)-((a.at(i)+ans)%b.at(i));
  }

  cout << ans << endl;
}
