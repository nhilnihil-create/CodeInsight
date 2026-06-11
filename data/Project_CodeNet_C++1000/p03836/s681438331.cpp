#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <bits/stdc++.h> 
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  ll ans=0;
  ll x=tx-sx,y=ty-sy;
  rep(i,y)cout << 'U';
  rep(i,x+1)cout << 'R';
  rep(i,y+1)cout << 'D';
  rep(i,x+1)cout << 'L';
  cout << 'U';
  cout << 'L';
  rep(i,y+1)cout << 'U';
  rep(i,x+1)cout << 'R';
  rep(i,y+1)cout << 'D';
  rep(i,x)cout << 'L';
return 0;}
