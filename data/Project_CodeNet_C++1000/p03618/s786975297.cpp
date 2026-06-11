#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string a;
  cin >> a;
  vector<ll> cnt(26,0);
  ll n=a.size();
  rep(i,n){
    int idx = a[i]-'a';
    cnt[idx]++;
  }
  ll ans = n*(n-1)/2+1;
  rep(i,26){
    ans -= cnt[i]*(cnt[i]-1)/2;
  }
  
  cout << ans << endl;
  return 0;
    

}
