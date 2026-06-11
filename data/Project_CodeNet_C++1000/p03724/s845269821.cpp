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
  int n,m; cin >> n >> m;
  map<int,int> mp;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    mp[a]++; mp[b]++;
  }
  for(auto c:mp){
    if(c.second%2==1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}