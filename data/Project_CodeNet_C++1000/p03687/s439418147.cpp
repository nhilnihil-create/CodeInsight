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
  cin>>s;
  int n=s.size();
  map<char,int> m;
  rep(i,0,n){
    m[s[i]]++;
  }
  int ans=inf;
  for(int i=97;i<=122;i++){
    int o=n;//o=文字列の長さ
    char c=i;
    if(m[c]==0)continue;
    int cnt=m[c];//cnt=指定文字のnagasa
   // cout<<m[c]<<endl;
    string t=s;
    int momo=0;
    while(o>cnt){
          rep(j,1,o){
                  if(t[j]==c&&t[j-1]!=c){
                     t[j-1]=t[j]; 
                    cnt++;
                  }
          }
      o--;
      if(t[o]==c)cnt--;
      momo++;
    }
    ans=min(ans,momo);
  }
         cout<<ans<<endl;
}