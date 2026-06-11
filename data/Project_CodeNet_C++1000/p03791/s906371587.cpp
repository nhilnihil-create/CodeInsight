#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007

int main(){
  int N;
  cin >> N;
  vector<int> x(N);
  rep(i,N){
    cin >> x[i];
  }

  vector<int> v;
  ll mn = 1;
  ll ret = 1;
  rep(i,x.size()){
    if(mn <= x[i]){
      v.push_back(mn);
      mn += 2;
    }else{
      ret *= (v.size()+1LL);
      ret %= MOD;
    }
  }

  for(ll i=1; i<=v.size(); i++){
    ret *= i;
    ret %= MOD;
  }
  cout << ret << endl;
  return 0;
}
