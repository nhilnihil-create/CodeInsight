#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::pair<ll,ll> pll;
typedef std::vector<pll> vpll;
typedef std::set<int> si;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
ll H,W,N;
ll a[100010],b[100010];
int main(){
  cin>>H>>W>>N;
  rep(i,N){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
  }
  vpll v;//
  rep(i,N){
    for(ll h=-1;h<=1;h++){
      for(ll w=-1;w<=1;w++){
	ll x=a[i]+h,y=b[i]+w;
	if(0<x&&x<H-1&&0<y&&y<W-1){
	  v.pb(mp(x,y));
	}
      }
    }
  }
  ll res[10];
  rep(i,10) res[i]=0;
  if(v.size()==0){
    res[0]=(H-2)*(W-2);
    rep(i,10) prin(res[i]);
  }
  else{
    std::sort(v.begin(),v.end());
    ll cnt=1;
    ll ccnt=0;
    rep(i,v.size()-1){
      if(v[i].first==v[i+1].first&&v[i].second==v[i+1].second) cnt++;
      else{
	res[cnt]++;
	cnt=1;
	ccnt++;
      }
    }
    res[cnt]++;
    ccnt++;
    res[0]=(H-2)*(W-2)-ccnt;
    rep(i,10) prin(res[i]);
  }
  return 0;
}
