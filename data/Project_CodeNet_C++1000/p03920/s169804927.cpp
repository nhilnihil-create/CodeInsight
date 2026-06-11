#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;



int main(){
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;

  vector<ll> ret;
  while(true){
    if(N == 0) break;
    if(N == 1 || N == 2){
      ret.push_back(N);
      break;
    }

    ll x = 0;
    for(ll i=1; i<=N; i++){
      if(x+i >= N){
        ret.push_back(i);
        N-=i;
        break;
      }
      x+=i;
    }
  }
  
  rep(i,ret.size()){
    cout << ret[i] << endl;
  }
  return 0;
}

