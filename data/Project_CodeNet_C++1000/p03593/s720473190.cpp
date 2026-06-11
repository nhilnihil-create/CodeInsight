#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll h,w;
  cin>>h>>w;
  vvc t(h,vc(w));
  vll k(26);
  rep(i,h) rep(j,w) {
    cin>>t[i][j];
    k[t[i][j]-'a']++;
  }
  if(h%2==0&&w%2==0){
    rep(i,26){
      if(k[i]%4!=0){
        COUT("No");
        return 0;
      }
    }
    COUT("Yes");
  }
  else if(h%2==1&&w%2==1){
    ll tate=h-1;
    ll yoko=w-1;
    ll cu=0;
    rep(i,26){
      if(cu*4==tate*yoko) break;
      if(k[i]>=4){
        cu++;
        k[i]-=4;
        i--;
      }
    }
    if(4*cu<tate*yoko) {
     COUT("No");
     return 0;
    }
    cu=0;
    rep(i,26){
      if(cu*2==h+w-2){
        COUT("Yes");
        return 0;
      }
      if(k[i]>=2){
        cu++;
        k[i]-=2;
        i--;
      }
    }
    COUT("No");
  }
  else{
    if(w%2==1) swap(h,w);
    if(h%2==1){
      ll cu=0;
      rep(i,26){
        if(4*cu==w*(h-1)) break;
        if(k[i]>=4){
          cu++;
          k[i]-=4;
          i--;
        }
      }
      if(cu*4<w*(h-1)) {
        COUT("No");
        return 0;
      }
      cu=0;
      rep(i,26){
        if(cu*2==w){
          COUT("Yes");
          return 0;
        }
        if(k[i]>=2){
        cu++;
        k[i]-=2;
        i--;
        }
      }
      COUT("No");
    }
  }
}
        