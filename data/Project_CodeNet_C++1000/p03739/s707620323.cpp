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
#define sort(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int main(){
  itn n; cin >> n;
  vector<ll> a(n);
  vector<ll> s(n);
  rep(i,n) cin >> a[i];
  s[0]=a[0];
  rep(i,n-1){
    s[i+1]=a[i+1]+s[i];
  }
  int b=-1;
  bool p=1;
  rep(i,n){
    if(s[i]==0){
      b=i;
      if(i+1<n&&s[i+1]<0) p=0;
    }
  }
  if(b==n-1){
    cout << 1+2*(n-1) << endl;
    return 0;
  }
  ll add1=0;
  ll add2=0;
  if(b!=-1){
    if((b+1)%2==0&&s[b+1]<0||(b+1)%2==1&&s[b+1]>0){
      add1=-1;
      add2=1;
    }
    else{
      add1=1;
      add2=-1;
    }
  }
  else{
    if(s[0]<0) add2=1-s[0];
    else add2=-1-s[0];
  }
  ll ans1=abs(add1);
  ll ans2=abs(add2);
  ll newadd1=0;
  ll newadd2=0;
  rep(i,n-1){
    if((s[i]+add1)*(s[i+1]+add1)>=0){
      if(s[i]+add1<0) newadd1=1-(s[i+1]+add1);
      else newadd1=(-1)-(s[i+1]+add1);
      add1+=newadd1;
      ans1+=abs(newadd1);
    }
  }
  rep(i,n-1){
    if((s[i]+add2)*(s[i+1]+add2)>=0){
      if(s[i]+add2<0) newadd2=1-(s[i+1]+add2);
      else newadd2=(-1)-(s[i+1]+add2);
      add2+=newadd2;
      ans2+=abs(newadd2);
    }
  }
  cout << min(ans1,ans2) << endl;
}