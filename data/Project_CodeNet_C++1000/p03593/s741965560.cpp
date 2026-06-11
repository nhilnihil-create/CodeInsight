#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll h,w;
  cin >> h >> w;
  vector<char> a(h*w);
  vl cnt(26,0);
  rep(i,h*w){
    cin >> a[i];
    rep(j,26){
      if(abc[j]==a[i]){
        cnt[j]++;
      }
    }
  }
  bool A=true;
  ll k,x=0,y=0;
  if(h%2==0&&w%2==0){
    rep(i,26){
      if(cnt[i]%4!=0){
        A=false;
      }
    }
  }
  else if(h*w%2==0){
    if(h%2==0){
      k=h/2;
    }
    else{
      k=w/2;
    }
    rep(i,26){
      if(cnt[i]%2!=0){
        A=false;
      }
      else if(cnt[i]%4==2){
        x++;
      }
      if(x>k){
        A=false;
      }
    }
  }
  else{
    rep(i,26){
      if(cnt[i]%2==1){
        y++;
        if(cnt[i]%4==3){
          x++;
        }
      }
      if(cnt[i]%4==2){
        x++;
      }
    }
    if(y!=1){
      A=false;
    }
    else if(x>(h/2)+(w/2)){
      A=false;
    }
  }
  if(A){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
