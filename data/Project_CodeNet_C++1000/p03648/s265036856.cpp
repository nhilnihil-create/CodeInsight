#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  ll K;
  cin >> K;

  ll a = (K + 50 - 1) / 50;
  vector<ll> v;
  rep(i,50) v.push_back(50+a-i-1);
  if(K%50 != 0){
    rep(i,50-(K%50)){
      v[i] -= 50;
      rep(j,50){
        if(i!=j) v[j]++;
      }
    }
  }

  cout << 50 << endl;
  rep(i,50){
    if(i!=0) cout << " ";
    cout << v[i];
  }
  cout << endl;
  
  return 0;
}
