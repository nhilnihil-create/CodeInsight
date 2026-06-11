#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main(){
 string s;
  cin>>s;
  int n=s.size();
  set<char>  c;
  rep(i,0,n){
    c.insert(s[i]);
  }
  char ans='Y';
  for(char i='a';i<='z';i++){
    if(c.count(i)){
      continue;
    }
    else{
      ans=i;
      break;
    }
  }
  if(ans=='Y')cout<<"None"<<endl;
  else cout<<ans<<endl;
}

