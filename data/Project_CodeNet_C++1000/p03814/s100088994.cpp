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

int main() {
  string s;
  cin>>s;
  int n=s.size();
  int a,z;
  rep(i,0,n){
    if(s[i]=='A'){
      a=i;break;
    }
  }
  for(int i=n-1;i>=0;i--){
   if(s[i]=='Z'){
    z=i;break; 
   }
  }
  cout<<z-a+1<<endl;
  
  
  
  
  
}