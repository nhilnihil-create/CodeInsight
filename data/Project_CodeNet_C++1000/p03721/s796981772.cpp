#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<pair<int,int>>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll>cnt(100001);
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    cnt[a] += b;
  }
  ll cn = 0;
  REP(i,1,100001){
    if(cn <= k && k <= (cn + cnt[i])){
      cout << i << endl;
      return 0;
    }
    cn += cnt[i];
  } 
  return 0;
}
