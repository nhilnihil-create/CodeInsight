#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  string s[3];
  int num[3];
//  int cnt[3];
  rep(i,0,3){
    cin>>s[i]; 
    num[i]=s[i].size();
   // cnt[i]=0;
  }
  char ans;
  char turn='a';
  while(true){
    if(turn=='a'){

      num[0]--;
      if(num[0]<0) {
       ans='A';
        break;
      }
      turn=s[0][s[0].size()-num[0]-1];
    }
    else if(turn=='b'){
		  num[1]--;
      if(num[1]<0) {
       ans='B';
        break;
      }
      turn=s[1][s[1].size()-num[1]-1];
    }
    else {
		  num[2]--;
      if(num[2]<0) {
       ans='C';
        break;
      }
      turn=s[2][s[2].size()-num[2]-1];
    }
  }
  cout<<ans<<endl;
}