#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int h,w;
  cin >> h >> w;
  map<char,int>mp;
  rep(i,h){
    rep(j,w){
      char c;
      cin >> c;
      mp[c]++;
    }
  }
  bool ok=true;
  if(h%2==0 && w%2==0){
    for(auto p:mp){
      if(p.second%4!=0)ok=false;
    }
  }
  if(h%2==1 && w%2==0){
    int cnt=0;
    for(auto p:mp){
      if(p.second%2!=0)ok=false;
      if(p.second%4==2)cnt++;
    }
    if(cnt>w/2)ok=false;
  }
  if(h%2==0 && w%2==1){
    int cnt=0;
    for(auto p:mp){
      if(p.second%2!=0)ok=false;
      if(p.second%4==2)cnt++;
    }
    if(cnt>h/2)ok=false;
  }
  if(h%2==1 && w%2==1){
    int cnt1=0,cnt2=0;
    for(auto p:mp){
      if(p.second%4==1 || p.second%4==3)cnt1++;
      if(p.second%4==2)cnt2++;
    }
    if(cnt1!=1 || cnt2>(h+w-2)/2)ok=false;
  }
  if(ok)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
    
        
}
