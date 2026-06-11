#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int h,w; cin >> h >> w;
  vector<vector<char> > g(h,vector<char>(w));
  rep(i,h)rep(j,w){
    cin >> g[i][j];
  }
  map<char,int> mp;
  rep(i,h)rep(j,w){
    mp[g[i][j]]++;
  }
  int cnt4=0;
  int cnt1=0;
  for(auto c:mp){
    cnt4+=c.second/4;
    if(c.second%2==1) cnt1++;
    if(cnt1>1){
      cout << "No" << endl;
      return 0;
    }
  }
  if((h%2==0||w%2==0)&&cnt1>0){
    cout << "No" << endl;
    return 0;
  }
  int hh=h,ww=w;
  if(h%2==1) hh=h-1;
  if(w%2==1) ww=w-1;
  int cnt41=hh*ww/4;
  if(cnt4>=cnt41){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}