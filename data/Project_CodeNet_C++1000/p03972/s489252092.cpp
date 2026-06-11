#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

int main(){
  ll W,H;cin >> W>>H;
  vll p(W),q(H);
  repeat(i,W){
    cin >> p[i];
  }
  p.push_back(INF);
  repeat(i,H){
    cin >> q[i];
  }
  q.push_back(INF);
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  ll pi=0,qi=0;
  ll ans = 0;
  repeat(i,W+H){
    ll pa = pi<W? p[pi]*(H+1-qi):INF;
    ll qa = qi<H? q[qi]*(W+1-pi):INF;
    if(p[pi]<q[qi]){
      ans += pa;
      pi++;
    }else{
      ans += qa;
      qi++;
    }
  }
  cout << ans << endl;
  return 0;
}
