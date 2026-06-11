#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define itn int
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend()-1)
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
  int n; ll W; cin >> n >> W;
  vector<ll> w(n);
  vector<ll> v0={0};
  vector<ll> v1={0};
  vector<ll> v2={0};
  vector<ll> v3={0};
  vector<ll> v(n);
  rep(i,n){
    cin >> w[i] >> v[i];
    if(w[i]==w[0]) v0.push_back(v[i]);
    if(w[i]==w[0]+1) v1.push_back(v[i]);
    if(w[i]==w[0]+2) v2.push_back(v[i]);
    if(w[i]==w[0]+3) v3.push_back(v[i]);
  }
  rsort(v0);
  rsort(v1);
  rsort(v2);
  rsort(v3);
  rep(i,v0.size()-1) v0[i+1]+=v0[i];
  rep(i,v1.size()-1) v1[i+1]+=v1[i];
  rep(i,v2.size()-1) v2[i+1]+=v2[i];
  rep(i,v3.size()-1) v3[i+1]+=v3[i];
  ll ans=0;
  rep(i,v0.size())rep(j,v1.size())rep(k,v2.size())rep(l,v3.size()){
    if(w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l<=W) chmax(ans,v0[i]+v1[j]+v2[k]+v3[l]);
  }
  cout << ans << endl;
}
