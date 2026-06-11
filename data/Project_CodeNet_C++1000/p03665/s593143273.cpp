#include<bits/stdc++.h>

#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed fixed<<setprecision(14)
using namespace std;
using pii=pair<int,int>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
const lol inf=(1LL<<60);
const lol Mod=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol n,m,k,r;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >>n>>m;
  int a[100];
  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  lol ans=0;
  lol a1=0;
  lol a2=1;
  for(int i=0;i<n;i++){
    if(a[i]&1){
      lol num=a1;
      a1+=a2;
      a2+=num;
    }else{
      a1*=2;
      a2*=2;
    }
  }
  if(m==0) cout <<a2<<'\n';
  else cout <<a1<<'\n';
  return (0);
}
