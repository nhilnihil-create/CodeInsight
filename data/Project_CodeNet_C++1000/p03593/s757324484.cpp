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
#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int x[26],y[26];

int main(){
  int h,w;
  cin >> h >> w;
  char a[h][w];
  rep(i,h)rep(j,w)cin >> a[i][j];
  int c[26]={};
  rep(i,h)rep(j,w)c[a[i][j]-'a']++;
  int cnt=0;
  rep(i,26)if(c[i]%2)cnt++;
  if(cnt!=(h*w)%2){
    cout << "No" << endl;
    return 0;
  }
  int p=0;
  rep(i,26)if(c[i]%4)p++;
  if(h%2==0 && w%2==0){
    if(p){
      cout << "No" << endl;
      return 0;
    }
  }
  else if(h%2 && w%2){
    if(p>(h+w)/2){
      cout << "No" << endl;
      return 0;
    }
  }
  else if(h%2==0){
    if(p>h/2){
      cout << "No" << endl;
      return 0;
    }
  }else{
    if(p>w/2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
return 0;}