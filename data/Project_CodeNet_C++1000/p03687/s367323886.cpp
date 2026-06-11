#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
  string s;
  cin>>s;
  map<char,ll> m;
  for(ll i=0;i<s.size();i++) m[s[i]]++;
  ll ans=INF,cnt,x;
  for(auto a:m){
      cnt=0;
      x=0;
      for(ll i=0;i<s.size();i++){
          if(a.first==s[i]){
              if(x>cnt) cnt+=x-cnt;
              x=0;
          }else x++;
      }
      if(x>cnt) cnt+=x-cnt;
      chmin(ans,cnt);
  }
  cout<<ans<<endl;
}
