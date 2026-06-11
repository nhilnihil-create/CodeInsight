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
  string s;
  int k;
  cin>>s>>k;
  ////
  int n=s.size();
  int cnt=0;
  while(k>0){
    if(cnt!=n-1){
      if(s[cnt]==97){
        cnt++;
        continue;
      }
        if(122-s[cnt]+1<=k){
          k-=122-s[cnt]+1;
          s[cnt]=97;
          cnt++;
        }
        else{
          cnt++;
        }
    }
    else{///cnt=n-1 
      k=k%26;
      if(s[cnt]+k>122){
        s[cnt]=s[cnt]-26+k; 
      }
      else{s[cnt]+=k;}
      k=0;
      
    }
  }
  cout<<s<<endl;
}