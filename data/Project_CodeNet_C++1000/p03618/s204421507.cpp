#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

int main(){
  string s; cin >> s;
  itn n=s.size();
  map<char,int> mp;
  rep(i,n) mp[s[i]]++;
  vector<ll> a(0);
  for(auto v:mp){
    a.push_back(v.second);
  }
  vector<ll> sa(a.size());
  sa[0]=a[0];
  rep(i,a.size()-1) sa[i+1]=sa[i]+a[i+1];
  ll ans=0;
  rep(i,sa.size()){
    ans+=a[i]*(sa[sa.size()-1]-sa[i]);
  }
  cout << 1+ans << endl;
}